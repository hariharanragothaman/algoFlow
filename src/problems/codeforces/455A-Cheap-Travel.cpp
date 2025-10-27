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

inline bool fileExists (const std::string& name)
{
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

inline void ldebug()
{
    if(fileExists("data.in"))
        cout << string(25, '-');
}


class Solution
{
public:

    void solve()
    {
        i64 n, m, a, b;
        cin >> n >> m >> a >> b;
        i64 opt1, opt2, opt3, opt4;
        opt1 = opt2 = opt3 = opt4 = LLONG_MAX;

        // Buy all Singles
        opt1 = n * a;

        // Buy mix
        opt2 = ((n / m) * b) + ((n % m) * a);

        // Buy only season
        if(m > n)
            opt3 = b;

        // Prefer season
        opt4 = ((n/m)+1) * b;

        vector<i64> results = {opt1, opt2, opt3, opt4};
        cout << *std::min_element(results.begin(), results.end()) << endl;
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
        ldebug();
    }
    return 0;
}
//
// Created by Hariharan Ragothaman on 10/27/25.
//
