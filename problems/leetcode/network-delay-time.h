class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& T, int n, int start)
    {
        using pii = pair<int, int>;
        unordered_map<int, vector<pair<int,int>>> G;

        vector<int> distance(n+1, numeric_limits<int>::max());
        vector<int> parent(n+1, -1);

        // Creating the graph
        for(int i=0; i<T.size(); i++)
        {
            vector<int> tmp = T[i];
            for(int i=0; i<tmp.size(); i++)
            {
                G[tmp[0]].push_back({tmp[1], tmp[2]});
            }
        }

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

        // Computing the minimum time, it will take
        int ans =  numeric_limits<int>::min();
        for(int i=1; i<=n; i++)
        {
            if(distance[i] == numeric_limits<int>::max())
                return -1;
            if( i != start)
                ans = max(ans, distance[i]);
        }


        return ans;
    }
};
