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

    bool check(double value, const vector<i64>& A, i64 l)
    {
        if(A.front() - value > 0.0) return false;

        for(int i=0; i+1 < A.size(); i++)
        {
            if(static_cast<double>(A[i+1] - A[i]) > 2.0 * value) return false;
        }

        if(static_cast<double>(l - A.back()) > value) return false;

        return true;
    }


    void solve()
    {
        int n, l;
        cin >> n >> l;
        vector<i64> A(n, 0);
        for(int i=0; i<n; i++)
            cin >> A[i];
        sort(A.begin(), A.end());

        double left, right;
        left = 0.0;
        right = static_cast<double>(l);

        while(right - left > 1e-12)
        {
            double pivot = (left + right) / 2.0;
            if(check(pivot, A, l))
            {
                right = pivot;
            }
            else
            {
                left = pivot;
            }
        }

        cout << fixed << setprecision(10) << right << '\n';
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
