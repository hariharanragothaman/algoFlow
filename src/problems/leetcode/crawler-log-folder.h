class Solution {
public:
    int minOperations(vector<string>& L)
    {
        string prev = "../";
        string curr = "./";
        int ans{};

        for(auto c: L)
        {
            if(c == prev and ans > 0)
            {
                ans -= 1;
            }
            else if(c != prev and c != curr)
            {
                ans += 1;
            }
        }
        return (ans > 0) ? ans : 0;
    }
};
