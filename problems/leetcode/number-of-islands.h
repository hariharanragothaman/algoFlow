template<typename T>
void print2DVector(const std::vector<std::vector<T>>& vec) {
    for (const auto& innerVec : vec) {
        for (const auto& element : innerVec) {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }
}

class Solution
{
public:
    void helper(vector<vector<char>>& G, int i, int j, int R, int C)
    {
        deque<pair<int, int>> Q;
        Q.push_back({i, j});
        set<pair<int, int>> S;

        while(Q.size() > 0)
        {
            auto [r, c] = Q.back();
            Q.pop_back();
            vector<vector<int>> directions = {{r+1, c}, {r, c+1}, {r-1, c}, {r, c-1}};
            vector<pair<int, int>> nei;
            for(auto c: directions)
            {
                if(0 <= c[0] && c[0]< R && c[1] >= 0 && c[1] < C)
                    nei.push_back({c[0], c[1]});
            }

            for(auto c: nei)
            {
                if(0 <= c.first && c.first < R && 0 <= c.second && c.second < C &&
                   S.find({c.first, c.second}) == S.end())
                {
                    if(G[c.first][c.second] == '1')
                    {
                        G[c.first][c.second] = '0';
                        S.insert({c.first, c.second});
                        Q.push_back({c.first, c.second});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& G)
    {
        int R = G.size(), C = G[0].size();
        int islands{};

        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                if(G[i][j] == '1')
                {
                    helper(G, i, j, R, C);
                    islands++;
                }
            }
        }
        return islands;
    }
};
