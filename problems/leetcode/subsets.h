class Solution
{
    set<vector<int>> ans;
public:
    bool is_valid_state(vector<int> state, vector<int>& arr, int val)
    {
        return state.size() == val and state.size() != 0;
    }

    vector<int> get_candidates(vector<int> state, vector<int>& arr, int start)
    {
        vector<int> candidates = {};
        int n = static_cast<int>(state.size());
        for(int i=start; i<arr.size(); i++)
        {
            candidates.push_back(arr[i]);
        }
        return candidates;
    }

    void backtrack(vector<int> state, vector<int>& arr, int start, int val)
    {
        if( is_valid_state(state, arr, val))
        {
            sort(state.begin(), state.end());
            ans.insert(state);
            return;
        }
        vector<int> C = get_candidates(state, arr, start);

        for(auto c: C)
        {
            state.push_back(c);
            start += 1;
            backtrack(state, arr, start, val);
            state.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& A)
    {
        int n = static_cast<int>(A.size());
        for(int j=1; j<=n; j++)
        {
            backtrack({}, A, 0, j);
        }

        vector<vector<int>> R;
        R.push_back({});
        for(auto c: ans)
            R.push_back(c);
        return R;
    }
};
