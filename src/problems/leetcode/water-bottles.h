#include "../../debug.h"

class Solution
{
    int ans;
public:

    void recur(int start, int n)
    {
        if(start < n)
        {
            return;
        }
        else
        {
            int gain = start / n;
            ans += gain;
            int rem = start % n;
            start = gain + rem;
            recur(start, n);
        }
    }


    int numWaterBottles(int A, int n)
    {
        ans += A;
        recur(A, n);
        return ans;
    }
};
