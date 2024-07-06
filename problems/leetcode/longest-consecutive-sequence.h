#include "../../debug.h"

class Solution {
public:
    int longestConsecutive(vector<int>& A)
    {
        int n = static_cast<int>(A.size());
        if(n == 0)
            return 0;

        sort(A.begin(), A.end());

        // Remove all duplicates
        A.erase(unique(A.begin(), A.end()), A.end());

        int ans = 1;
        int mx = 1;

        for(auto c: A)
            cout << c << " ";
        cout << endl;

        for(int i=1; i<n; i++)
        {
            if (A[i]-A[i-1] == 1)
            {
                ans += 1;
                mx = max(mx, ans);
            }
            else
            {
                ans = 1;
            }
        }
        return mx;
    }
};
