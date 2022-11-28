#include "bits/stdc++.h"
#include "../../../debug.h"
using namespace std;

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
