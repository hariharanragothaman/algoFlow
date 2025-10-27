/*
 *   Aggressive cows
 *   Farmer John has built a new long barn, with 𝑛 stalls. The stalls are located along a straight line at positions 𝑥1,𝑥2,...,𝑥𝑛.
 *   His 𝑐 cows don't like this barn layout and become aggressive towards each other once put into a stall.
 *   To prevent the cows from hurting each other, Farmer John wants to assign the cows to the stalls,
 *   such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
 *
 */
#ifndef ONLINE_JUDGE
#include "headers.h"
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

bool cost(vector<int> A, int n, int minDist, int c)
{
    int cows = 1;
    int lastCowPos = A[0];

    for(int i=1; i<n; i++)
    {
        if(A[i] - lastCowPos >= minDist)
        {
            cows += 1;
            lastCowPos = A[i];
            if(cows >= c)
                return true;
        }
    }
    return false;
}



void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> A(n, 0);
    for(int i=0; i<n; i++) cin >> A[i];
    sort(A.begin(), A.end());

    int l = 1;
    int r = 1000000000;

    int result;

    while(l <= r)
    {
        int p = l + (r-l) / 2;
        if(cost(A, n, p, c))
        {
            result = p;
            l = p + 1;
        }
        else
        {
            r = p - 1;
        }
    }

    cout << result << endl;
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
