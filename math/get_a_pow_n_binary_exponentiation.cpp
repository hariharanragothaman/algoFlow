#include "bits/stdc++.h"
#include "../debug.h"
using namespace std;

int binpow( int a, int n)
{
    int res = 1;
    while(n)
    {
        if(n & 1)
        {
            res *= a;
            --n;
        }
        else
        {
            a *= a;
            n >>= 1;
        }
    }
    return res;
}

int main()
{
    int a = 2;
    int n = 3;
    int res = binpow(a, n);
    cout << "The result is: "<< res;
    return 0;
}
