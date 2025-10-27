class Solution {
public:
    int minCost(string C, vector<int>& T)
    {
        int ans{};
        int n = static_cast<int>(C.size());

        vector<pair<char, int>> St;
        vector<int> tmp;

        St.push_back({C[0], T[0]});

        for(int i=1; i<n; i++)
        {
            char ch = C[i];
            auto [tos, val] = St.back();
            if(ch != tos)
            {
                St.push_back({ch, T[i]});
            }
            else if (ch == tos)
            {
                // Incoming is lesser
                if(T[i] <= val)
                {
                    ans += T[i];
                }
                    // Incoming is greater
                else
                {
                    ans = ans + val;
                    St.back().second = T[i];
                }
            }
        }
        return ans;
    }
};
