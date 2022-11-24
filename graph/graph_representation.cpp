#include "bits/stdc++.h"
#include "../debug.h"
using namespace std;

void basicGraph(vector<vi> &g)
{
    // Making this similar to a 'defaultdict' implementation
    map<int, std::vector<int>> graph;

    int n = g.size();

    for(auto c: g)
        graph[c[0]].emplace_back(c[1]);

    /* Printing the graph  keys*/
    for(auto it = graph.begin(); it != graph.end(); ++it)
    {
        cout << it->first << " ";
        for (auto c: it->second)
            cout << c << " ";
        cout << endl;
    }

}

int main()
{

    vector<vi> g = {{1, 2}, {1, 3}, {3, 4}};

    /* Printing the 2D vector*/
    for(int i = 0; i < g.size(); i++)
    {
        for(int j= 0; j < g[i].size(); j++)
        {
            cout << g[i][j];
        }
        cout << endl;
    }

    cout <<"Calling the basic graph representation" << endl;
    basicGraph(g);

    return 0;
}
