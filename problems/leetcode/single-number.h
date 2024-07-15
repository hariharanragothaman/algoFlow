class Solution {
public:
    int singleNumber(vector<int>& A)
    {
        unordered_map<int, int> H;
        for(auto c: A) H[c]++;
        for(auto c: H)
            if(c.second == 1)
                return c.first;
        return INT_MAX;
    }
};
