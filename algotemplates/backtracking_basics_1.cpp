#include "../debug.h"

/*
    Basically, when we see small constraints, and different combinations
    we, are looking at backtracking.

    The most important parts of the backtracking are:
        We are generating all combos using bruteforce.

    # Basic Back-tracking Pseudo-Code:
    def backtrack(state):
        if there are no more states that can be generated from current-state,
            then return
        Change the current state to it's neighbouring state.
        backtrack(state)

        Here, the state is the index, once we reach the end of the array; there are no more states to monitor.
        For each index, we have 2 options - include it in our current subsequence, or not.
            So we have a condition for both those scenarios,
            Call recursive function for both the scenarios.
        Both the cases, where we include (or) not must go to the next state.
*/

class Solution
{
    vector<vector<int>> ans;
public:
    void recursive(int i, vector<int> S, vector<int> A, int n)
    {
        if(S.size() >= 2)
            ans.push_back(S);
        if(i == n)
            return;
        if(S.size() == 0 or (i >= 0 and A[i] >= S.back()))
        {
            vector<int> tmp(S.begin(), S.end());
            tmp.push_back(A[i]);
            recursive(i+1, tmp, A, n);
        }
        recursive(i+1, S, A, n);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        int n = (int) nums.size();
        recursive(0, {}, nums, n);
        return ans;
    }
};

int main()
{
    vector<int> nums = {4, 6, 7, 7};
    Solution obj;
    obj.findSubsequences(nums);
    return 0;
}
