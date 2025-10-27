class Solution {
public:
    string minWindow(string s, string t)
    {
        int n = static_cast<int>(s.size());
        int ans = INT_MAX;
        string result{};

        unordered_map<char, int> H;
        for(auto c: t)
            H[c]++;

        int distinct_chars = static_cast<int>(H.size());
        int formed{};

        unordered_map<char, int> G;
        int upper{}, lower{};
        int l = 0;
        for(int r=0; r<n; r++)
        {
            G[s[r]]++;
            if(H.find(s[r]) != H.end() and H[s[r]] == G[s[r]])
                formed++;

            while(l <=r && formed == distinct_chars)
            {
                int length = r-l+1;
                if(length <= ans)
                {
                    lower = l;
                    upper = r;
                    ans = length;
                }
                G[s[l]]--;

                if(H.find(s[l]) != H.end() and G[s[l]] < H[s[l]])
                    formed--;
                l++;
            }
        }
        return (ans != INT_MAX) ? s.substr(lower, ans) : "";
    }
};
