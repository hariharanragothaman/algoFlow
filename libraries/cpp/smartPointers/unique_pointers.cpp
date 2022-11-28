#include "bits/stdc++.h"
#include "../../../debug.h"
using namespace std;

/*
 * std::unique_ptr exclusively takes care of its resource.
 * It automatically releases the resource if it goes out of scope.
 * If there is no copy semantic required, it can be used in containers and algorithms of the Standard Template Library.
 * std::unique_ptr is as cheap and fast as a raw pointer, if you use no special deleter.
 *
 * It has the following methods
 *
 *  get         Returns the pointer to the resource
 *  get_deleter Returns the delete function
 *  release     Returns a pointer to the resource and releases it.
 *  reset       Resets the resource
 *  swap        Swaps the resources
 *
 */

struct MyInt
{
    MyInt(int i):i_(i){}
    ~MyInt()
    {
        cout << "Good bye from " << i_ << endl;
    }
    int i_;
};

int main()
{
    unique_ptr<MyInt> uniquePtr1{new MyInt(1998)};
    cout << uniquePtr1.get() << endl;               // 0x15b5010

    unique_ptr<MyInt> uniquePtr2{move(uniquePtr1)};
    cout << uniquePtr1.get() << endl;               // 0
    cout << uniquePtr2.get() << endl;               // 0x15b5010
    {
        unique_ptr<MyInt> localPtr{new MyInt(2003)};
    }                                                      // Good bye from 2003

    uniquePtr2.reset(new MyInt(2011));              // Good bye from 1998
    MyInt* myInt= uniquePtr2.release();
    delete myInt;                                   // Good by from 2011

    unique_ptr<MyInt> uniquePtr3{new MyInt(2017)};
    unique_ptr<MyInt> uniquePtr4{new MyInt(2022)};
    cout << uniquePtr3.get() << endl;               // 0x15b5030
    cout << uniquePtr4.get() << endl;               // 0x15b5010

    swap(uniquePtr3, uniquePtr4);
    cout << uniquePtr3.get() << endl;               // 0x15b5010
    cout << uniquePtr4.get() << endl;               // 0x15b5030
    return 0;
}
