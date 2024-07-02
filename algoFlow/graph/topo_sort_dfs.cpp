#include "../../debug.h"


struct Edge
{
    int source;
    int destination;
};

vector<int> topological_sort(vector<vector<int>>& graph, int& nodes)
{
    vector<int> result;
    vector<int> visited(nodes);

    vector<int> stack;
    for(int i=0; i<nodes; i++)
        stack.emplace_back(i);

    while(stack.size() > 0)
    {
        int node = stack.back();
        stack.pop_back();
        if(node < 0)
            result.emplace_back(~node);
        else if(visited[node] == 0)
        {
            visited[node] = 1;
            stack.emplace_back(~node);

            for(auto e: graph[node])
                stack.emplace_back(e);
        }
    }

    // Add a cycle check here...
    for(auto c: result)
    {
        for (auto d: graph[c])
        {
            if (visited[d])
                return {};
            visited[c] = 0;
        }
    }

    reverse(result.begin(), result.end());
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
    for (auto e: edges)
        graph[e.source].push_back(e.destination);

    vector<int> result = topological_sort(graph, nodes);
    for(auto c: result)
        cout << c << endl;
}
