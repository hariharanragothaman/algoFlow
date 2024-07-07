#include "../../debug.h"

/* one way to make a compile-time constant variable is to use the const keyword.
 * If the const variable has an integral type and a constant expression initializer, it is a compile-time constant.
 * All other const variables are treated as runtime constants.
 *
 *  Enlist the compiler’s help to ensure we get a compile-time constant variable where we desire one
 *  A constexpr (which is short for “constant expression”) variable is always a compile-time constant.
 *  As a result, a constexpr variable must be initialized with a constant expression, otherwise a compilation error will result.
 */

int main()
{
    int a { 5 };       // not const at all
    const int b { a }; // obviously a runtime const (since initializer is non-const)
    const int c { 5 }; // obviously a compile-time const (since initializer is a constant expression)

//    const int d { someVar };    // not obvious whether this is a runtime or compile-time const
//    const int e { getValue() }; // not obvious whether this is a runtime or compile-time const

    constexpr double gravity { 9.8 }; // ok: 9.8 is a constant expression
    constexpr int sum { 4 + 5 };      // ok: 4 + 5 is a constant expression
    constexpr int something { sum };  // ok: sum is a constant expression

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

//    constexpr int myAge { age };      // compile error: age is not a constant expression
//    constexpr int f { five() };       // compile error: return value of five() is not a constant expression

    return 0;
}
