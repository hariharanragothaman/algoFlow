#include "../../../debug.h"

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
