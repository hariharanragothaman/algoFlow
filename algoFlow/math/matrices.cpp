#include "../../debug.h"

const std::pair<int, int> moves[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

vector<vector<int>> getTranspose(vector<vector<int>> A)
{
    int R = A.size();
    int C = A[0].size();
    vector<vector<int>> Transpose(C, vector<int>());

    if(R == 0)
        return Transpose;

    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            Transpose[j].push_back(A[i][j]);
        }
    }
    return Transpose;
}

vector<vector<int>> getNeighbours(int r, int c, int R, int C)
{
    vector<vector<int>> neighbours;
    vector<vector<int>> adj = {{-1, 0}, {0, -1},{1, 0}, {0, 1}};

    for(int i=0; i<4; i++)
    {
        int nr = adj[i][0] + r;
        int nc = adj[i][1] + c;

        if(nr >=0 && nr < R && nc >=0 and nc < C) {
            neighbours.push_back({nr, nc});
        }
    }
    return neighbours;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> transpose = getTranspose(arr);
    for(int i=0; i<transpose.size(); i++)
    {
        for (int j = 0; j < transpose[0].size(); j++) {
            cout << transpose[i][j];
        }
        cout << endl;
    }

    /* To parse the matrix and get the neighbours of each of the elements */
    int R = arr.size();
    int C = arr[0].size();

    for(int i=0; i<R; i++)
    {
        for(int j=0; j<R; j++)
        {
            vector<vector<int>> nei = getNeighbours(i, j, R, C);
            cout << "The neighbours of " << i << " " << j << endl;
            for(auto c: nei)
                cout << c[0] << c[1] << endl;
            cout << "**************************" << endl;

        }
    }
}
