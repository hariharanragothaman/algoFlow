/*
 *  Please refer: https://leetcode.com/problems/koko-eating-bananas/description/
 */

class Solution
{
public:
    bool f(vector<int>& A, int p, int h)
    {
        vector<int> H;
        long long int sum = 0;
        for(auto c: A)
        {
            int q = c / p;
            int r = c % p;
            int tmp = r > 0 ? q+1 : q;
            sum += tmp;
        }
        return (sum <= h) ? true : false;
    }
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int l = 1;
        int r = 1000000000;
        int ans = INT_MAX;
        sort(piles.begin(), piles.end());

        while(l <= r)
        {
            int p = l + (r-l) / 2;
            if(f(piles, p, h))
            {
                ans = min(ans, p);
                r = p - 1;
            }
            else
            {
                l = p + 1;
            }
        }

        return ans;
    }
};
