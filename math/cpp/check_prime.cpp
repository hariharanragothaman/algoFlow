#include "bits/stdc++.h"
#include "../../debug.h"
using namespace std;

bool prime(int n)
{
    if (n < 2 )
        return false;
    if (n <= 3)
        return true;
    if ( !(n % 2 ) or !( n % 3))
        return false;

    for (int i=5; i*i <= n; i+=6)
        if ( !(n%i) or !(n%(i+2)))
            return false;

    return true;
}

int main()
{
    int n = 7;
    bool res = prime(n);
    cout << res;
    return 0;
}
