#include "../../debug.h"

class Solution
{
    vector<vector<int>> ans;
public:
    bool is_valid(vector<int> state, vector<int>&A, int& t)
    {
        int sum = accumulate(state.begin(), state.end(), 0);
        return sum == t;
    }

    vector<int> get_candidates(vector<int> state, vector<int>&A, int& t)
    {
        int sum = accumulate(state.begin(), state.end(), 0);
        vector<int> candidates;
        for(auto c: A)
        {
            if(sum + c <= t)
            {
                candidates.push_back(c);
            }
        }
        return candidates;
    }

    void backtrack(vector<int> state, vector<int>&A, int& t)
    {
        if(is_valid(state, A, t))
        {
            ans.push_back(state);
            return;
        }
        vector<int> C = get_candidates(state, A, t);
        for(auto c: C)
        {
            state.push_back(c);
            backtrack(state, A, t);
            state.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& A, int t)
    {
        backtrack({}, A, t);
        set<vector<int>> result;
        for(auto c: ans)
        {
            sort(c.begin(), c.end());
            result.insert(c);
        }
        vector<vector<int>> output(result.begin(), result.end());
        return output;
    }
};
