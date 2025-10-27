#include "../../debug.h"


struct Compare
{
    bool operator()(const vector<int> A, const vector<int> B)
    {
        return A[2] < B[2];
    }
};

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& P, int k)
    {
        priority_queue<vector<int>, vector<vector<int>>, Compare> PQ;

        for(auto c: P)
        {
            int x = c[0], y = c[1];
            int d = pow(x,2) + pow(y, 2);
            PQ.push({x, y, d});
        }

        while(PQ.size() > k)
        {
            PQ.pop();
        }

        vector<vector<int>> ans;
        while(PQ.size() > 0)
        {
            vector<int> tmp = PQ.top();
            ans.push_back({tmp[0], tmp[1]});
            PQ.pop();
        }

        return ans;
    }
};
