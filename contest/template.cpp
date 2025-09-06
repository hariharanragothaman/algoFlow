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

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")

#ifndef ONLINE_JUDGE
#include "debug.h"
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

template<typename T>
void debug(const T& msg)
{
    if(fileExists("data.in"))
        cout << msg << endl;
}

void debug2()
{
    if(fileExists("data.in"))
        cout << string(25, '-') << endl;
}


void debug3()
{
    cout <<  string(25, '*') << endl;
}



class Solution
{
private:

public:
    void solve()
    {
        int one_side = 4;
        int support = 4; // to join to sides.
        int one_cube = 2 * one_side + support;
        /*
         *
         * for n cubes joineed t- there will be n-1 supports
         * 1 cube  = 2 sides + 1 join
         * 2 cubes = 3 sides + 2 join
         * 3 cubes = 4 sides + 3 join
         *
         * n cubes = n+1 sides + (n-1) join
         */
        int n;
        cin >> n;
        cout << ((n+1) * 4) + ((n)*4) << endl;

    }
};


int32_t main()
{
    auto start = std::chrono::high_resolution_clock::now();

    FAST_IO();
    int T = 1;
//    cin >> T;

    Solution sol;
    while(T--)
    {
        sol.solve();
        debug2();
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
