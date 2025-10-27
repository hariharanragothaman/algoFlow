#include "../../../debug.h"

/*
 * The function std::forward, defined in the header <utility>,
 * empowers you to write function templates.
 *
 * Typical use cases for std::forward are factory functions or constructors.
 *
 * Factory functions are functions which create an object and
 * must therefore identically pass the arguments.
 *
 *
 * If you use std::forward together with variadic templates,
 * you can define completely generic function templates.
 * Your function template can accept an arbitrary number of arguments and forward them unchanged.
 */

using std::initializer_list;

struct MyData
{
    MyData(int, double, char){};
};

template <typename T, typename...  Args>
T createT(Args&&... args)
{
    return T(std::forward<Args>(args)... );
}

int a= createT<int>();
int b= createT<int>(1);

std::string s= createT<std::string>("Only for testing.");
MyData myData2= createT<MyData>(1, 3.19, 'a');

typedef std::vector<int> IntVec;
IntVec intVec= createT<IntVec>(initializer_list<int>({1, 2, 3}));

int main()
{
    return 0;
}
