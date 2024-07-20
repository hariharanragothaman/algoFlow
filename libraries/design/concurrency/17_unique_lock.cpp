#include "../../../debug.h"
/*
 * The usage of std::unique_lock is more expensive than the usage of std::lock_guard.
 * On the contrary, a std::unique_lock can be created with and without mutex,
 * can explicitly lock or release its mutex or can delay the lock of its mutex.
 */

/*
 * Because of the argument std::defer_lock of the std::unique_lock,
 * the locking of a.mut and b.mut is deferred.
 * The locking takes place atomically in the call std::lock(guard1, guard2).
 */

struct CriticalData
{
    mutex mut;
};

void deadLockResolved(CriticalData& a, CriticalData& b)
{
    unique_lock<mutex>guard1(a.mut, defer_lock);
    cout << this_thread::get_id() << ": get the first mutex" << endl;
    this_thread::sleep_for(chrono::milliseconds(1));
    unique_lock<mutex>guard2(b.mut, defer_lock);
    cout << this_thread::get_id() << ": get the second mutex" << endl;
    cout << this_thread::get_id() << ": atomic locking";
    lock(guard1, guard2);
}

int main()
{
    CriticalData c1;
    CriticalData c2;

    thread t1([&]{ deadLockResolved(c1, c2); });
    thread t2([&]{ deadLockResolved(c2, c1); });

    t1.join();
    t2.join();
}
