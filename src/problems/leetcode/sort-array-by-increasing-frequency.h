struct Compare
{
    bool operator()(pair<int,int> a, pair<int, int> b)
    {
        if(a.second != b.second)
        {
            return a.second < b.second;
        }
        else
        {
            return a.first > b.first;
        }
        return 0;
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& A)
    {
        vector<pair<int, int>> B;
        unordered_map<int, int> H;
        for(auto c: A)
            H[c]++;
        for(auto k: H)
            B.push_back({k.first, k.second});
        sort(B.begin(), B.end(), Compare());
        vector<int> ans;
        for(auto c: B)
        {
            for(int i=0; i<c.second; i++)
                ans.push_back(c.first);
        }
        return ans;

    }
};
