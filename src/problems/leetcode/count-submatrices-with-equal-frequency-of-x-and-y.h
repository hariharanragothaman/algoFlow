class Solution {

    vector<vector<int>> Count2DSum (char ch, const vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> result(rows, vector<int>(cols, 0));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++)
                result[r][c] = (grid[r][c] == ch)? 1 : 0;
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 1; c < cols; c++)
                result[r][c] += result[r][c-1];
        }

        for (int c = 0; c < cols; c++) {
            for (int r = 1; r < rows; r++)
                result[r][c] += result[r-1][c];
        }
        return result;
    }

public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> cnt_x = Count2DSum('X', grid);
        vector<vector<int>> cnt_y = Count2DSum('Y', grid);

        int result = 0;
        for (int r = 0; r < rows; r ++) {
            for (int c = 0; c < cols; c ++) {
                if (cnt_x[r][c] == cnt_y[r][c] && cnt_x[r][c] > 0) result ++;
            }
        }
        return result;
    }
};
