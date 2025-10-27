#include "../../debug.h"

struct Compare
{
    bool operator()(const int a, const int b)
    {
        return a > b;
    }
};


class KthLargest
{
    int K;
    priority_queue<int, vector<int>, Compare> PQ;
public:
    KthLargest(int k, vector<int>& nums)
    {
        K = k;
        for(auto c: nums)
            PQ.push(c);

        while(PQ.size() > k)
        {
            PQ.pop();
        }
    }

    int add(int val)
    {
        PQ.push(val);
        while(PQ.size() > K)
        {
            PQ.pop();
        }
        return PQ.top();
    }
};
