/*
    செயல் பேசும் ஆழம் இங்கே சொற்கள் பேசுமா?
    Focus, Determination and Sheer-Will
    The woods are lovely, dark and deep,
    But I have promises to keep,
    And miles to go before I sleep,
    And miles to go before I sleep.

    ---------------------------------------------
    1. Remember the data-type of the I/P's you are getting
    2. Function calls are not free.

 PROBLEM STATEMENT: https://codeforces.com/group/c3FDl9EUi9/contest/263096/problem/J

*/

#ifndef ONLINE_JUDGE
#include "../../debug.h"
#else
#include "bits/stdc++.h"
#include <sys/stat.h>
using namespace std;
#endif

#define FAST_IO() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long
#define endl '\n'

inline bool fileExists (const std::string& name)
{
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}


void solve()
{
    int n;
    cin >> n;
    vector<int> A(n, 0);
    vector<int> ans(n, -1);
    stack<int> S;

    for(int i=0; i<n; i++)
    {
        cin >> A[i];
        while(!S.empty() && A[i] > A[S.top()])
        {
            ans[S.top()] = i + 1;
            S.pop();
        }
        S.push(i);
    }

    // Responding to Queries
    int q;
    cin >> q;
    int index;
    while(q--)
    {
        cin >> index;
        index = index - 1;
        cout << ans[index] << endl;
    }
}

int32_t main()
{
    auto start = std::chrono::high_resolution_clock::now();

    FAST_IO();
    int T = 1;
    while(T--)
    {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

#ifndef ONLINE_JUDGE
    if(fileExists("data.in"))
    {
        cout << "Time taken: ";
        cout << duration.count() << endl;
    }
    return 0;
#else
#endif
}
