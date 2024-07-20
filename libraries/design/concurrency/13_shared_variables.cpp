#include "../../../debug.h"
/*
 *
 *  DATA RACE
 *  A data race is a state in which at least two threads access a shared data at the same time, and at least one of the threads is a writer.
 *  Therefore, the program has undefined behavior.
 *
 *  You can observe very well the interleaving of threads if a few threads write to std::cout.
 *  The output stream std::cout is, in this case, the shared variable.
 *
 */


// Without the mutex lock() and unlock(), the cout stream is uncoordinated due to a data race.
mutex mutexCout;

struct Worker
{
    Worker(string n):name(n){};
    void operator() ()
    {
        for (int i= 1; i <= 3; ++i)
        {
            this_thread::sleep_for(chrono::milliseconds(200));
            mutexCout.lock();
            cout << name << ": " << "Work " << i << endl;
            mutexCout.unlock();
        }
    }
private:
    string name;
};

int main()
{
    thread herb= thread(Worker("Herb"));
    thread andrei= thread(Worker(" Andrei"));
    thread scott= thread(Worker (" Scott"));
    thread bjarne= thread(Worker(" Bjarne"));

    herb.join();
    andrei.join();
    scott.join();
    bjarne.join();
}
