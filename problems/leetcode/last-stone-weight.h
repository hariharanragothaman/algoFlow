#include "../../debug.h"

struct MaxTop
{
    bool operator()(const int a, const int b)
    {
        return a < b;
    }
};

class Solution
{
public:
    int lastStoneWeight(vector<int>& S)
    {
        priority_queue<int, vector<int>, MaxTop> PQ;
        for(auto c: S)
        {
            PQ.push(c);
        }

        while(PQ.size() > 1)
        {
            int val1 = PQ.top();
            PQ.pop();
            int val2 = PQ.top();
            PQ.pop();
            if(val1 == val2)
                continue;
            else
                PQ.push(abs(val1-val2));
        }

        return (PQ.size() > 0) ? PQ.top() : 0;
    }
};
