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
        cout << string(25, '-'); cout << endl;
}


class Solution
{
public:
    void solve()
    {
        i64 n, f;
        cin >> n >> f;
        vector<int> A(n, 0);
        for(int i=0; i<n; i++) cin >> A[i];

        int l{}, r=0, mx{};
        i64 csum{};

        while(r <= n-1)
        {
            csum += A[r];
            while(csum > f)
            {
                csum -= A[l];
                l += 1;
            }
            mx = max(mx, r-l+1);
            r += 1;
        }
        cout << mx << endl;
    }
};

int main()
{
    fast_io();
    int T = 1;
//    cin >> T;
    Solution object;
    while(T--)
    {
        object.solve();
        ldebug();
    }
    return 0;
}
