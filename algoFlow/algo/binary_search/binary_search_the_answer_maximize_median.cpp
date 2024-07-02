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

*/

#ifndef ONLINE_JUDGE
#include "../../../debug.h"
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


bool cost(vector<int> A, int n, int pivot, int k)
{
    int start = n / 2;
    int moves = 0;
    for(int i=start; i<n;  i++)
    {
        if(pivot  - A[i] > 0)
            moves += pivot - A[i];

        if(moves > k)
            return false;
    }
    if(moves <= k)
        return true;
    else
        return false;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n, 0);
    for(int i=0; i<n; i++) cin >> A[i];
    sort(A.begin(), A.end());

    int left = 1;
    int right = 2e9;
    int ans = A[n/2];

    while(left <= right)
    {
        int pivot = left + (right-left) / 2;
        if(cost(A, n, pivot, k))
        {
            ans = max(ans, pivot);
            left = pivot + 1;
        }
        else
        {
            right = pivot - 1;
        }
    }
    cout << ans << endl;
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
