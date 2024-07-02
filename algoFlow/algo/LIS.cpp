#include "../../debug.h"

int LIS(vector<int> A)
{
    int n = static_cast<int>(A.size());
    vector<int> DP(n, 1);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[i] > A[j])
                DP[i] = max(DP[i], DP[j] + 1);
        }
    }
    return *max_element(DP.begin(), DP.end());
}

int main()
{
    return 0;
}
