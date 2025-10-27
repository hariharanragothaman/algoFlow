#include "../../debug.h"

class Solution
{
public:
    int passThePillow(int n, int t)
    {
        if(t < n)
        {
            return t + 1;
        }

        int q = t / (n-1);
        int r = t % (n-1);

        if(q % 2 == 0)
        {
            if(r > 0)
            {
                return r + 1;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            if(r > 0)
            {
                return n - r;
            }
            else
            {
                return n;
            }
        }
        return 0;
    }
};
