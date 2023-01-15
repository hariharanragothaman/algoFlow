#include "../debug.h"

int GCD(int a, int b)
{
    return gcd(a, b);
}

int LCM(int a, int b)
{
    return (a*b) / GCD(a, b);
}

int main()
{
    cout << GCD(6, 20) << endl;
    cout << LCM(6, 20) << endl;
}
