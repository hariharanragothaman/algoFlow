#include "../../debug.h"

class Solution
{
    vector<vector<int>> ans;
public:
    bool is_valid_state(vector<int> state, vector<int>& arr)
    {
        return state.size() == arr.size();
    }

    vector<int> get_candidates(vector<int> state, vector<int>& arr)
    {
        vector<int> candidates = {};
        for(auto c: arr)
        {
            if(find(state.begin(), state.end(), c) == state.end())
            {
                candidates.push_back(c);
            }
        }
        return candidates;
    }

    void backtrack(vector<int> state, vector<int>& arr)
    {
        if( is_valid_state(state, arr))
        {
            ans.push_back(state);
            return;
        }
        vector<int> C = get_candidates(state, arr);
        for(auto c: C)
        {
            state.push_back(c);
            backtrack(state, arr);
            state.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& A)
    {
        backtrack({}, A);
        return ans;
    }
};
