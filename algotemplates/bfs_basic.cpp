#include "../debug.h"
using namespace std;

vector<vector<int>> G;
int nodes;
int start;

int main()
{
    queue<int> Q;
    vector<bool> visited(n);
    vector<int> D(n);
    vector<int> P(n);

    Q.push(start);
    visited[start] = true;
    P[start] = -1;

    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();

        for(auto nei: G[node])
        {
            if(!visited[nei])
            {
                Q.push(nei);
                D[nei] = D[node] + 1;
                P[nei] = node;
            }
        }
    }
}
