class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& A)
    {
        int R = static_cast<int>(A.size());
        int C = static_cast<int>(A[0].size());

        vector<int> ans{};

        for(int i=0; i<R; i++)
        {
            vector<int> row = A[i];
            int col = -1;
            int row_min = INT_MAX;

            for(int j=0; j<C; j++)
            {
                if(A[i][j] <= row_min)
                {
                    row_min = A[i][j];
                    col = j;
                }
            }

            // now 'col' is the column to check
            int col_max = 0;
            for(int k=col; k<col+1; k++)
            {
                for(int l=0; l<R; l++)
                {
                    col_max = max(col_max, A[l][k]);
                }
            }

            if(row_min == col_max)
            {
                ans.push_back(row_min);
            }
        }

        return ans;

    }
};
