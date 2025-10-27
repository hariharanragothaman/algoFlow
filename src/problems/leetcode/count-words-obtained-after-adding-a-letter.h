class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& T)
    {
        unordered_set<string> s;
        for (auto &w : startWords)
        {
            sort(begin(w), end(w));
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                int p = lower_bound(begin(w), end(w), ch) - begin(w);
                if (p == w.size() || w[p] != ch)
                    s.insert(w.substr(0, p) + ch + w.substr(p));
            }
        }

        int ans{};
        for (auto w : T)
        {
            sort(begin(w), end(w));
            ans += s.count(w);
        }
        return ans;
    }
};
