#include "../headers.h"

string toBaseK(int n, int k)
{
    string res = "";
    int rem;
    while(n)
    {
        rem = n % k;
        n /= k;
        res += to_string(rem);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    return 0;
}
