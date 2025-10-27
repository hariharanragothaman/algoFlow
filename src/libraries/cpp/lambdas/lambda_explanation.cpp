#include "../../../debug.h"

/*

A lambda is just a another way to make a class and provide an operator() for it.
The [] part of the lambda describes the member variables and whether they are captured by reference or value.
The () part of the lambda is the parameter list for the operator() and the {} part is the body of that function.
The mutable part tells the compiler to make the operator() non const as it is const by default.

*/

// Hence this becomes --->
int init = 0;
//auto lambda = [init]() mutable { return ++init;};

// ----->> This below

struct compiler_generated_name
{
    int init; // we captured by value
    auto operator()() // since we used mutable this is non const
    {
        return ++init;
    }
};

/*
I used a struct here for brevity of typing but a lambda is specified as a class type so class could be used.
This means the init is the same init from the last iteration as you only ever capture once.
This is important to remember as, the code below:
*/

auto generate_lambda()
{
    int foo = 0;
    return [&foo](){ return ++foo; };
}
/*
 * Will leave you with a dangling reference to foo when the function returns and using it is undefined behavior.
 */

int main()
{
    return 0;
}
