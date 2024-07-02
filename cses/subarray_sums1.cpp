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
#include "../debug.h"

#else
#include "bits/stdc++.h"
#include <sys/stat.h>
using namespace std;
#endif

#define FAST_IO() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long
#define endl '\n'

/*
 *  FUNCTIONS FOR DEBUGGING
 */

inline bool fileExists (const std::string& name)
{
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

void solve()
{
    int n, x;
    cin >> n >> x;
    int val;
    vector<int> A(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> val;
        A[i] = val;
    }

    int sum = 0;
    int l = 0;
    int ans = 0;

    for(int r=0; r<n; r++)
    {
        sum += A[r];
        while(sum > x)
        {
            sum -= A[l];
            l++;
        }
        if(sum == x)
            ans += 1;
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
        if(fileExists("data.in"))
            cout << string(25, '-') << endl;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

#ifndef ONLINE_JUDGE
    if(fileExists("data.in"))
    {
        cout << "Time taken: ";
        cout << duration.count() << " ms" << endl;
    }
#endif

    return 0;
}
