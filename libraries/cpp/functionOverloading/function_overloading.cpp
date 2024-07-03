#include "../../../debug.h"

int addInteger(int x, int y)
{
    return x + y;
}

double addDouble(double x, double y)
{
    return x + y;
}

// Function overloading creates multiple functions with the same name
// Each identically named function has different parameter types
// Functions can be overloaded as long as they can be differentiated by the compiler
// Compiler matches the overload -> This is called overload resolution
// Note: Operators can also be overloaded

int add(int x, int y)
{
    return x + y;
}

double add(double x, double y)
{
    return x + y;
}


int main()
{
    std::cout << add(1, 2); // calls add(int, int)
    std::cout << '\n';
    std::cout << add(1.2, 3.4); // calls add(double, double)
    return 0;
}
