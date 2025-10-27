#include "../../debug.h"


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int T)
    {
        int R = A.size(), C = A[0].size();
        // Given an integer, tell whether it's in the matrix or not.
        vector<int> BB;
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                BB.push_back(A[i][j]);

        auto idx = lower_bound(BB.begin(), BB.end(), T)- BB.begin();
        return idx >=0 and idx < BB.size() and BB[idx] == T;
    }
};
