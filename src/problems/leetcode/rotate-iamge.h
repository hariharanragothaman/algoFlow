#include "../../debug.h"

class Solution {
public:
    void rotate(vector<vector<int>>& A)
    {
        int R = static_cast<int>(A.size());
        int C = static_cast<int>(A[0].size());

        // Transpose
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<=i; j++)
            {
                swap(A[i][j], A[j][i]);
            }
        }

        // Reverse every row
        for(int i=0; i<R; i++)
        {
            reverse(A[i].begin(), A[i].end());
        }
    }
};
