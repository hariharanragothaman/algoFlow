#include "../../../debug.h"

/*
 *  Given an undirected graph, perform 0-1 BFS
 */

void bfsZerotoOne(unordered_map<int, vector<int>>& G, int start)
{
    int n = G.size();
    vector<int> distance(n+1, INT_MAX);
    distance[start] = 0;

    deque<int> Q;
    Q.push_back(start);

    while (!Q.empty())
    {
        int node = Q.front();
        Q.pop_front();

        for (auto nei : G[node])
        {
            if (distance[nei] > distance[node] + 1)
            {
                distance[nei] = distance[node] + 1;
                Q.push_back(nei);
            }
        }
    }

    // Printing the distance map
    for(int i=0; i<distance.size(); i++)
        cout << i << ": " << distance[i] << endl;
}

int main()
{
    unordered_map<int, vector<int>> G;  // Graph given with no weights
    vector<pair<int, int>> A = {{5, 1}, {5, 2}, {1, 3}, {2, 6}, {2, 4}};
    for(auto c: A)
    {
        G[c.first].push_back(c.second);
        G[c.second].push_back(c.first);
    }

    // Printing the Graph
    for(auto key: G)
    {
        cout << "Key: " << key.first <<" ";
        for(auto val: key.second)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    int start_node = 2;
    bfsZerotoOne(G, start_node);
    return 0;
}
