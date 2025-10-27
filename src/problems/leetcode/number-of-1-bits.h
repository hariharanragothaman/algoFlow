class Solution {
public:
    int hammingWeight(int n)
    {
        return __builtin_popcount(n);
    }
};

class Solution2 {
public:
    int hammingWeight(int n)
    {
        int ans{};
        while(n)
        {
            ans += n & 1;
            n  = n >> 1;
        }
        return ans;
    }
};
