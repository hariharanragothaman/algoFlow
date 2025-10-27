#include "../../../debug.h"

void djikstra(vector<vector<int>> T, int n, int start)
{
    using pii = pair<int, int>;
    unordered_map<int, vector<pair<int,int>>> G;

    vector<int> distance(n+1, numeric_limits<int>::max());
    vector<int> parent(n+1, -1);

    /* Creating the graph */
    for(int i=0; i<T.size(); i++)
    {
        vector<int> tmp = T[i];
        for(int i=0; i<tmp.size(); i++)
        {
            G[tmp[0]].push_back({tmp[1], tmp[2]});
        }
    }

    /* Applying the algorithm */
    distance[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push({0, start});

    while(!PQ.empty())
    {
        auto [dist, vertex] = PQ.top();
        PQ.pop();
        for(auto edge: G[vertex])
        {
            int to = edge.first;
            int len = edge.second;

            if(distance[vertex] + len < distance[to])
            {
                distance[to] = distance[vertex] + len;
                parent[to] = vertex;
                PQ.push({distance[to], to});
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }
}


int main()
{
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, start = 2;
    /* times is in the form of {u, v, w}
     * 'n' is the number of vertices
     * 'start' index is given
     * Here, we find the shortest path from 'start' to all vertices
     */
     djikstra(times, n, start);
     return 0;
}
