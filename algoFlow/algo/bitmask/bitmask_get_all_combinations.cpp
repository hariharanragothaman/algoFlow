#include "../../../debug.h"

int main()
{
    vector<int> A = {4, 6, 7, 7};
    int n = A.size();

    set<vector<int>> ans;
    // Going through all combinations
    for(int msk = 0; msk < (1<<n); msk++)
    {
        vector<int> current;
        for(int j=0; j<n; j++)
        {
            if(msk & (1<<j))
            {
                current.push_back(A[j]);
            }
        }
        if( current.size() >= 2 and is_sorted(current.begin(), current.end()))
            ans.insert(current);
    }
}
