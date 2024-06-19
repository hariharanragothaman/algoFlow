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
        cout << "---------------------------------" << endl;
}

void debug3()
{
    if(fileExists("data.in"))
        cout << "*********************************" << endl;
}

template<typename T>
void print(const T &v)
{
    if(fileExists("data.in"))
    {
        for(auto c: v)
            cout << c << " ";
        cout << endl;
    }
}

void recurse(int n)
{
    if(n == 1)
    {
        cout << n << endl;
        return;
    }
    else
    {
        if(n&1)
        {
            cout << n << " ";
            n = 3*n+1;
            recurse(n);
        }
        else
        {
            cout << n << " ";
            n >>= 1;
            recurse(n);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    recurse(n);
}

int32_t main()
{
    auto start = std::chrono::high_resolution_clock::now();

    FAST_IO();
    int T = 1;
    while(T--)
    {
        solve();
        debug2();
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

#ifndef ONLINE_JUDGE
    if(fileExists("data.in"))
    {
        cout << "Time taken: ";
        cout << duration.count() << " ms" << endl;
    }
#endif

    return 0;
}
