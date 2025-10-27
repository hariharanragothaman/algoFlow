#include "../../debug.h"

struct MinTop
{
    bool operator()(const int a, const int b)
    {
        return a > b;
    }
};

class Solution
{
public:
    int findKthLargest(vector<int>& A, int k)
    {
        priority_queue<int, vector<int>, MinTop> PQ;
        for(auto c: A)
        {
            PQ.push(c);
        }
        while(PQ.size() > k)
        {
            PQ.pop();
        }
        return PQ.top();

    }
};
