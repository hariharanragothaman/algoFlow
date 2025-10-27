#include "../../debug.h"

class Solution {
public:
    int maxSubArray(vector<int>& A)
    {
        int n = A.size();
        int left = 0, right = 0;
        int ans = A[left];
        int current_sum = 0;

        while(right < n)
        {
            current_sum += A[right];
            ans = max(current_sum, ans);

            while(current_sum < 0)
            {
                current_sum -= A[left];
                left++;
            }

            right++;
        }
        return ans;
    }
};
