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
using i64 = long long;
#define endl '\n'

inline bool fileExists (const std::string& name)
{
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}


auto print_vector = [](auto c){ cout << c << " ";};

class Solution
{
private:
public:
    void solve()
    {
        vector<int> A = {1, 2, 3, 4, 5};
        for_each(A.begin(), A.end(), print_vector);
    }
};


int32_t main()
{
    auto start = std::chrono::high_resolution_clock::now();

    FAST_IO();

#ifndef ONLINE_JUDGE
    if (fileExists("data.in")) {
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    }
#endif
    int T = 1;
//    cin >> T;

    Solution sol;
    while(T--)
    {
        sol.solve();
    }
#ifndef ONLINE_JUDGE
    if (fileExists("data.in")) {
        auto stop = std::chrono::high_resolution_clock::now();
        auto us   = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
        cerr << "Time taken: " << us << " μs\n";
    }
#endif

    return 0;
}
