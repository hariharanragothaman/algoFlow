#include "../../debug.h"

class Solution
{
    vector<vector<int>> ans;
public:
    bool is_valid_state(vector<int> state, vector<int>& arr)
    {
        if(state.size() <= 1)
        {
            return false;
        }
        else
        {
            for(int i=1; i<state.size(); i++)
            {
                if(state[i] < state[i-1])
                {
                    return false;
                }
            }
        }
        return true;
    }

    vector<pair<int, int>> get_candidates(vector<int> state, vector<int>& arr, int index)
    {
        vector<pair<int, int>> candidates = {};
        for(int i=index+1; i<arr.size(); i++)
        {
            candidates.push_back({arr[i], i});
        }
        return candidates;
    }

    void backtrack(vector<int> state, vector<int>& arr, int index)
    {
        if( is_valid_state(state, arr))
        {
            ans.push_back(state);
        }
        vector<pair<int, int>> C = get_candidates(state, arr, index);
        for(auto c: C)
        {
            auto [value, idx] = c;
            state.push_back(value);
            backtrack(state, arr, idx);
            state.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        backtrack({}, nums, -1);
        set<vector<int>> S;
        for(auto c: ans)
            S.insert(c);
        vector<vector<int>> output(S.begin(), S.end());
        return output;
    }
};
