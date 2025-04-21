#include <iostream>
#include <memory>
using namespace std;

struct Widget
{
    // Here compiler will generate all 5 functions correctly.
    unique_ptr<int[]> data = make_unique<int[]>(1024);
};
