#include "../../debug.h"

class Solution {
public:
    int minDifference(vector<int>& A)
    {
        int n = static_cast<int>(A.size());
        if(n < 4)
        {
            return 0;
        }

        int ans = numeric_limits<int>::max();
        sort(A.begin(), A.end());
        for(int i=0; i<4; i++)
        {
            int diff = A[n-4+i] - A[i];
            ans = min(ans, diff);
        }
        return ans;
    }
};
