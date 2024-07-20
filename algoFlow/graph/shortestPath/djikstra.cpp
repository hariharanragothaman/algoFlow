#include "../../../debug.h"

void dijkstra(int start, vector<pair<int, long long>>* edges, long long *arr, int n, bool* visited, int* parent)
{
    set<pair<long long, int>> s;
    s.insert({0, 0});
    while (!s.empty())
    {
        pair<long long, int> top = *s.begin();
        int element = top.second;
        visited[element] = true;
        int distance = top.first;
        arr[element] = distance;
        s.erase(s.begin());

        for (int i = 0; i < edges[element].size(); i++)
        {
            if (visited[edges[element][i].first])
                continue;
            if (distance + edges[element][i].second < arr[edges[element][i].first])
            {
                auto f = s.find({arr[edges[element][i].first], edges[element][i].first});
                if (f != s.end())
                    s.erase(f);
                s.insert({distance + edges[element][i].second, edges[element][i].first});
                arr[edges[element][i].first] = distance + edges[element][i].second;
                parent[edges[element][i].first] = element;
            }
        }
    }
}
void solve()
{

    int n, m;
    cin >> n >> m;
    vector<pair<int, long long>> *edges = new vector<pair<int, long long>>[n];
    int* parent = new int[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--; 	//considering bidirectional edges
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    long long* shortest_paths = new long long[n]; // from the vertex 0
    for (int i = 0; i < n; i++)
        shortest_paths[i] = 1e18;
    shortest_paths[0] = 0;

    int start = 0;
    bool *visited = new bool[n]();

    dijkstra(start, edges, shortest_paths, n, visited, parent);

    if (shortest_paths[n - 1] != 1e18)
    {
        int i = n - 1;
        vector<int> v1;
        while (parent[i] != i)
        {
            v1.push_back(parent[i] + 1);
            i = parent[i];
        }
    }
    else
        cout << -1 << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T=1;
    while(T--) solve();
    return 0;

}
