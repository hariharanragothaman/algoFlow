#include "../../debug.h"

/* Creating a custom functor - object of this needs to be created */
struct Compare
{
    bool operator()(const vector<int> A, const vector<int> B)
    {
        return A[0] < B[0];
    }
};

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& T)
    {
        A.push_back(T);
        sort(A.begin(), A.end(), Compare());

        // Merge the intervals into B
        vector<vector<int>> B = {A[0]};

        // Merge Intervals
        for(int i=1; i<A.size(); i++)
        {
            if (A[i][0] <= B.back()[1])
            {
                B.back()[1] = max(A[i][1], B.back()[1]);
            }
            else
            {
                B.push_back(A[i]);
            }
        }
        return B;
    }
};
