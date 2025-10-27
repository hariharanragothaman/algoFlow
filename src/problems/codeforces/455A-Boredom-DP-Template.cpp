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
        int n; cin >> n;
        vector<int> A(n, 0);
        for(int i=0; i<n; i++) cin >> A[i];

        unordered_map<int, int> H;
        for(auto c: A) H[c]++;

        const i64 MX = *max_element(A.begin(), A.end());

        vector<i64> DP(MX+1, 0);
        DP[0] = 0;
        DP[1] = H[1] * 1;
        for(int j=2; j <= MX; j++)
        {
            DP[j] = max(DP[j-1], DP[j-2] + (1LL * j * H[j]));
        }
        cout << DP[MX] << endl;
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
