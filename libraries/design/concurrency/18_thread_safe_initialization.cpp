#include "../../../debug.h"
/*
 * If you don’t modify the data, it’s sufficient to initialize them in a thread-safe way.
 * C++ offers various ways to achieve this:
 *          using a constant expression,
 *          using static variables with block scope,
 *          and using the function std::call_once in combination with the flag std::once::flag.
 */

struct MyDouble
{
    constexpr MyDouble(double v):val(v){};
    constexpr double getValue()
    {
        return val;
    }
private:
    double val;
};

// Static variables in a block - another thread safe way
void blockScope()
{
    static int MySharedDataInt= 2011;
}

/*
 *
 * std::call_once takes two arguments: the flag std::once_flag and a callable.
 * The C++ runtime guarantees with the help of the flag std::once_flag that the callable is executed exactly once.
 */

once_flag onceFlag;
void do_once()
{
    call_once(onceFlag, []{ cout << "Only once." << endl; });
}

int main()
{
    constexpr MyDouble obj(10.5);
    thread t1(do_once);
    thread t2(do_once);

    t1.join();
    t2.join();
}
