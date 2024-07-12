class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> ans{};
        int n = static_cast<int>(s.size());

        unordered_map<char, int> H;
        for(int i=0; i<n; i++)
            H[s[i]] = i;

        int cut{}, anchor{};

        for(int i=0; i<n; i++)
        {
            int cut = max(cut, H[s[i]]);
            if(i == cut)
            {
                int l = cut - anchor + 1;
                ans.push_back(l);
                anchor = i+1;
            }
        }
        return ans;
    }
};
