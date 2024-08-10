#include <iostream>
#include <thread>
#include <condition_variable>
#include <string>
#include <mutex>
using namespace std;

mutex m;
condition_variable cv;
std::string output;
bool ready = false;
bool processed = false;


void worker_fn()
{
    unique_lock lk(m);
    // wait until main() sends data.
    cv.wait(lk, []{return ready; });
    // after the wait, we own the lock
    cout << "Worker thread is processing data" << endl;
    output += " After Processing..." ;
    // Send data back to main()
    processed = true;
    cout << "Worker thread processing is completed" << endl;
    lk.unlock();
    cv.notify_one();
}

int main()
{
    thread t1(worker_fn);
    output = "Data from Main";
    // Send data to worker thread
    {
        lock_guard lk(m);
        ready = true;
        cout << "main() signals data ready for processing" << endl;
    }

    cv.notify_one();
    // wait for worker
    {
        unique_lock lk(m);
        cv.wait(lk, [] {return processed;});
    }
    cout << "Back in main(), data = " << output << endl;
    t1.join();
}
