#include "bits/stdc++.h"
#include "../../../debug.h"
using namespace std;

class Foo
{
public:
    int bar;
    Foo(int num): bar(num) {};
};

int main()
{
    std::cout << Foo(42).bar << std::endl;
    return 0;
}
