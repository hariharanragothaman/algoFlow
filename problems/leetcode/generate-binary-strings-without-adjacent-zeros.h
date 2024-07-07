class Solution
{
    vector<string> ans;
public:
    bool is_valid_state(string state, int n)
    {
        if(state.size() < n)
        {
            return false;
        }
        else if(state.size() == n)
        {
            for(int i=0; i<n-1; i++)
            {
                string ss = state.substr(i, 2);
                int cnt = count(ss.begin(), ss.end(), '1');
                if(cnt < 1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    vector<string> get_candidates()
    {
        return {"0", "1"};
    }

    void backtrack(string state, int n)
    {
        if(state.size() > n)
        {
            return;
        }
        if( is_valid_state(state, n))
        {
            ans.push_back(state);
            return;
        }
        vector<string> C = get_candidates();
        for(int i=0; i<C.size(); i++)
        {
            state += C[i];
            backtrack(state, n);
            state.pop_back();
        }

    }

    vector<string> validStrings(int n)
    {
        backtrack("", n);
        return ans;
    }
};
