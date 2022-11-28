#include "bits/stdc++.h"
#include "../../../debug.h"
using namespace std;

/*
 * You should encapsulate a mutex in a lock to release the mutex automatically.
 * A lock is an implementation of the RAII idiom because the lock binds the lifetime of the mutex to its lifetime.
 * C++11 has std::lock_guard for the simple and std::unique_lock for the advanced use case, respectively.
 * Both need the header <mutex>.
 * With C++14 C++ has a std::shared_lock which is in the combination with the mutex std::shared_time_mutex the base for reader-writer locks.
 *
 */


std::mutex coutMutex;
struct Worker
{
    Worker(std::string n):name(n){};
    void operator() ()
    {
        for (int i= 1; i <= 3; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));

            /*
             *  std::lock_guard supports only the simple use case.
             *  Therefore it can only bind its mutex in the constructor and release it in the destructor.
             *  So the synchronization of the worker example is reduced to the call of the constructor.
             */
            std::lock_guard<std::mutex> myLock(coutMutex);


            std::cout << name << ": " << "Work " << i << std::endl;
        }
    }
private:
    std::string name;
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
