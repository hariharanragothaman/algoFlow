#include "bits/stdc++.h"
#include "../../../debug.h"
using namespace std;

/*
 * By using the keyword thread_local, you have thread local data also known as thread local storage.
 * Each thread has its copy of the data.
 * Thread-local data behaves like static variables.
 * They are created at their first usage, and their lifetime is bound to the lifetime of the thread.
 */

std::mutex coutMutex;
thread_local std::string s("hello from ");

void addThreadLocal(std::string const& s2)
{   s += s2;
    std::lock_guard<std::mutex> guard(coutMutex);
    std::cout << s << std::endl;
    std::cout << "&s: " << &s << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::thread t1(addThreadLocal, "t1");
    std::thread t2(addThreadLocal, "t2");
    std::thread t3(addThreadLocal, "t3");
    std::thread t4(addThreadLocal, "t4");

    t1.join();
    t2.join();
    t3.join();
    t4.join();

}
