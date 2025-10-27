/*
 *    FOCUS + DETERMINATION + SHEER-WILL
 */

#ifndef ONLINE_JUDGE
#include "headers.h"
#else
#include "bits/stdc++.h"
    #include "sys/stat.h"
    using namespace std;
#endif

using i64 = long long;
using u64 = unsigned long long;
using i32 = int;
using u32 = unsigned int;
using ld  = long double;
//--------------------------
using vi   = vector<int>;
using vl   = vector<long long>;
using vvi  = vector<vector<int>>;
using vvl  = vector<vector<long long>>;
using pii  = pair<int,int>;
using pll  = pair<long long,long long>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using iset = set<int>;
using imap = map<int,int>;
//--------------------------

inline void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Solution
{

public:
    vector<i64> sieve(int n)
    {
        vector<int> arr(n + 1, 0);
        vector<i64> primes;

        for (int i = 2; i * i <= n; i++)
            if (arr[i] == 0)
                for (int j = i * i; j <= n; j += i)
                    arr[j] = 1;

        for (int i = 2; i <= n; i++)
            if (arr[i] == 0)
                primes.push_back(i);

        return primes;
    }

    void solve()
    {
        int n; cin >> n;
        i64 value{};

        // Pre-compute the primes
        vector<i64> primes = sieve(1e6+1);

        for(int i=0; i<n; i++)
        {
            cin >> value;
            i64 r = sqrt(value);
            if( r * r != value)
            {
                cout << "NO" << endl;
            }
            else if(binary_search(primes.begin(), primes.end(), r))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
};

int main()
{
    fast_io();
    int T = 1;
    Solution object;
    while(T--)
    {
        object.solve();
    }
    return 0;
}
