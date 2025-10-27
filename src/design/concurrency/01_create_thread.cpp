#include "../../../debug.h"


void helloFunction()
{
    cout << "Hello from a function." << endl;
}


class HelloFunctionObject
{
public:
    void operator()() const
    {
        cout << "Hello from a function object." << endl;
    }
};

int main()
{
    std::cout << std::endl;

    std::thread t1(helloFunction);

    HelloFunctionObject helloFunctionObject;
    std::thread t2(helloFunctionObject);

    std::thread t3([]{std::cout << "Hello from a lambda." << std::endl;});

    /*
     * the main thread is waiting until its children are done.
     */
    t1.join();
    t2.join();
    t3.join();

    std::cout << std::endl;

    /*
     * The three threads are executed in an arbitrary order; even the three output operations can interleave.
     * The creator of the child - the main thread in our case - is responsible for the lifetime of the child.
     */

    return 0;
}
