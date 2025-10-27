class Solution {
public:
    int minimumLength(string s)
    {
        int n = static_cast<int>(s.size());
        unordered_map<char, vector<int>> H;

        for(int i=0; i<n; i++)
        {
            H[s[i]].push_back(i);
        }

        int cnt{};
        for(auto c: H)
        {
            int sz = c.second.size();
            while(sz >=3)
            {
                cnt += 2;
                sz -= 2;
            }
        }

        cout << cnt <<endl;
        return n-cnt;
    }
};
