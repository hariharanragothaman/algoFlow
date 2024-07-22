struct Compare
{
    bool operator()(pair<string, int> p1, pair<string, int> p2)
    {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    vector<string> sortPeople(vector<string>& A, vector<int>& H)
    {
        int n = static_cast<int>(A.size());
        vector<pair<string, int>> S;
        for(int i=0; i<n; i++)
            S.push_back({A[i], H[i]});
        sort(S.begin(), S.end(), Compare());

        vector<string> ans;
        for(auto c: S)
            ans.push_back(c.first);
        return ans;
    }
};
