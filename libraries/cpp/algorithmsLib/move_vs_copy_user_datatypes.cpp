#include "../../../debug.h"


class MyData{
    MyData(MyData&& m) = default; // move constructor
    MyData& operator = (MyData&& m) = default; // move assignment
    MyData(const MyData& m) = default; // copy constructor
    MyData& operator = (const MyData& m) = default; // copy assignment
};

int main()
{
    return 0;
}
