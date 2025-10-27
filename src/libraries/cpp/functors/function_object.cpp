#include "../../../debug.h"

/*
 *  A function object, or functor, is any type that implements operator().
 *  This operator is referred to as the call operator or sometimes the application operator.
 *  The C++ Standard Library uses function objects primarily as sorting criteria for containers and in algorithms.
 */

class Functor
{
public:
    int operator()(int a, int b)
    {
        return a < b;
    }
};

int main()
{
    Functor f;
    int a = 5;
    int b = 7;
    int ans = f(a, b);
    cout << ans << endl;
}
