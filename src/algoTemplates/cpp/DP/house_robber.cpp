#include "../headers.h"

class Solution {
public:
    int rob(vector<int>& A)
    {
        int n = A.size();
        if(n < 2)
            return A[0];

        vector<int>DP(n+1, 0);
        DP[0] = A[0];
        DP[1] = max(A[0], A[1]);

        for(int i=2; i<n; i++)
        {
            DP[i] = max(DP[i-1], A[i] + DP[i-2]);
        }
        return DP[n-1];
    }
};
