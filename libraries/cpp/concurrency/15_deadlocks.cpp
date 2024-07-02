#include "../../../debug.h"
/*
 * A deadlock is a state in which two or more threads are blocked
 * because each thread waits for the release of a resource before it releases its resource.
 */

/*
 * You can get a deadlock very quickly if you forget to call m.unlock().
 * That happens for example in the case of an exception in the function getVar().
 *
 *      m.lock();
 *      sharedVar= getVar();
 *      m.unlock()
 *
 *  Locking two mutexes in the wrong order is another typical reason for a deadlock.
 *  Consider the example below
 */

struct CriticalData
{
    std::mutex mut;
};

void deadLock(CriticalData& a, CriticalData& b)
{
    a.mut.lock();
    std::cout << "get the first mutex\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    b.mut.lock();
    std::cout << "get the second mutex\n";

    a.mut.unlock();
    b.mut.unlock();
}

int main()
{
    CriticalData c1;
    CriticalData c2;
    std::thread t1([&]{ deadLock(c1, c2); });
    std::thread t2([&]{ deadLock(c2, c1); });
    t1.join();
    t2.join();
}


/*
 *
 * The short time window of one millisecond (std::this_thread::sleep_for(std::chrono::milliseconds(1)))
 * is enough to produce with high probability a deadlock
 * because each thread is waiting forever on the other mutex.
 * The result is a standstill.
 *
 */
