#include "../../../debug.h"
using namespace std;

/*
 *
 * Smart pointers are one of the most important additions to C++ because they empower you to implement explicit memory management in C++.
 * Beside the deprecated std::auto_ptr, C++ offers three different smart pointers.
 * They are defined in the header <memory>.
 *
 * Firstly there is the std::unique_ptr, which models the concept of exclusive ownership.
 *      Owns exclusively the resource. Can’t be copied.
 *
 * Secondly, there is the std::shared_ptr, who models the concept of shared ownership.
 *      Has a reference counter for the shared variable.
 *      Manages the reference counter automatically.
 *      Deletes the resource, if the reference counter is 0.
 *
 * Lastly, there is the std::weak_ptr. std::weak_ptr is not so smart, because it has only a thin interface.
 *      Helps to break cycles of std::shared_ptr.
 *      Doesn’t modify the reference counter.
 *
 * Its job is it to break cycles of std::shared_ptr. It models the concept of temporary ownership.
 *
 */

#include "../../../debug.h"
using namespace std;

class Resource
{
public:
    Resource()
    {
        cout << "Constructor:: Resource Acquired" << endl;
    }

    ~Resource()
    {
        cout << "Destructor:: Resource Released" << endl;
    }

    void doSomething()
    {
        cout << "Resource is doing something" << endl;
    }

};

void someFunction()
{
    Resource *ptr new Resource();
}

int main()
{

    return 0;
}
