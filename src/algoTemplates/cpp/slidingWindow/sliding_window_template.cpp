#include "../headers.h"


void solve()
{
    int n;  cin >> n;
    int t; cin >> t; // This is the limit / param in the question
    vector<int> A(n, 0);
    for(int i=0; i<n; i++) cin >> A[i];

    long long sum = 0;
    int l = 0, best = 0;
    for (int r = 0; r < n; ++r)
    {
        sum += A[r];
        while (sum > t) sum -= A[l++];   // shrink just enough
        best = max(best, r - l + 1);     // record after shrinking
    }
}
