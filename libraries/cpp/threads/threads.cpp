#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void printMessage(int id)
{
    mtx.lock();  // mutex lock and mutex unlock.
    cout << "Thread: " << id << " is running " << endl;
    mtx.unlock();

}

int main()
{
    thread t1(printMessage, 1);
    thread t2(printMessage, 2);

    t1.join();
    t2.join();
    return 0;
}
