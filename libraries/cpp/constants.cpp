#include "../../debug.h"

/*
 *  No need to use const when passing by value
 *  Prefer const (over) MACROS
 *  Not assigning a value to const, will lead to compilation error
 */

/*
 * as-if rule - Compiler can optimize code, as long - observable behavior is not changed
 * const expressions can be evaluated during compile time.
 *
 * Compile time constant's value is known at compile time.
 * literals (string literals, '5', '1.2') , constexpr variables,
 * const integral variables - const inst x{5} | In Modern C++, constexpr variables are preferred.
 * Non-type template parameters
 * Enumerators
 */

/*
 *
 * Constant expressions (including constexpr variables and constexpr functions)
 * can help produce code that is faster, smaller, and safer.
 * Some C++ features require constant expressions.
 */

int main()
{
    int x{4};
    const double gravity {9.8};
    // const double G; - Results in compilation error
    return 0;
}
