#include "bits/stdc++.h"
#include "../../debug.h"
using namespace std;

set<int> find_all_divisors(int n)
{
    set<int> factors;
    int s = sqrt(n);
    for(int i = 1;i <= s;i++)
    {
        if (n%i==0)
        {
            if (n/i == i) // check if divisors are equal
                factors.insert(i);
            else
            {
                factors.insert(i);
                factors.insert(n/i);
            }
        }
    }
    factors.insert(n);
    return factors;
}

int main()
{
    int n = 16;
    set<int> res = find_all_divisors(n);
    for(auto c: res) cout << c << " " << endl;
    return 0;
}
