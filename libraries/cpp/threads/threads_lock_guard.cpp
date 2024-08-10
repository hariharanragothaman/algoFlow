#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void printMessage(int id)
{
    lock_guard<mutex> lock(mtx); // We can use lock_guard instead of explicit mutex lock and unlock()
    cout << "Thread: " << id << " is running " << endl;

}

int main()
{
    thread t1(printMessage, 1);
    thread t2(printMessage, 2);

    t1.join();
    t2.join();
    return 0;
}
