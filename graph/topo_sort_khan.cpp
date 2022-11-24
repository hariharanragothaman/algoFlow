#include "bits/stdc++.h"
#include "../debug.h"
using namespace std;

struct Edge
{
    int source;
    int destination;
};

vector<int> topological_sort(vector<vector<int>>& graph, vector<int>& indegree, int& nodes)
{
    vector<int> result;
    vector<int> no_in_degree;
    for(int i=0; i<nodes; i++)
    {
        if (indegree[i] == 0)
            no_in_degree.push_back(i);
    }

    while(no_in_degree.size() > 0)
    {
        int n = no_in_degree.back();
        no_in_degree.pop_back();

        result.push_back(n);
        for(int m: graph[n])
        {
            indegree[m] -= 1;
            if(indegree[m] == 0)
                no_in_degree.push_back(m);
        }
    }

    /* Check for cycles */
    for(int i=0; i<nodes; i++)
    {
        if(indegree[i])
            return {};
    }
    return result;
}

int main() {
    vector <Edge> edges = {{0, 6},
                           {1, 2},
                           {1, 4},
                           {1, 6},
                           {3, 0},
                           {3, 4},
                           {5, 1},
                           {7, 0},
                           {7, 1}};
    int nodes = 8;

    // Create adjacency List
    vector <vector<int>> graph;
    graph.resize(nodes);

    vector<int> indegree(nodes, 0);
    for (auto e: edges)
    {
        graph[e.source].push_back(e.destination);
        indegree[e.destination]++;
    }

    vector<int> result = topological_sort(graph, indegree, nodes);
    for(auto c: result)
        cout << c << endl;
}
