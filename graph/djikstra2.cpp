#include "bits/stdc++.h"
#include "../debug.h"
using namespace std;

#define int long long
using namespace std;

typedef  pair<int, int> pii
typedef vector< pii > vii;
#define INF 1E18

vii *G;
vi Dist;
vi tugfa;

void Dijkstra(int source, int N) {
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    Dist.assign(N,INF);
    Dist[source] = 0;
    Q.push({0,source});
    while(!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        for(auto &c : G[u]){
            int v = c.first;
            int w = c.second;
            //cout << u << " " << v << endl;
            if(Dist[v] > Dist[u]+w){
                tugfa[v] = u;
                Dist[v] = Dist[u]+w;
                Q.push({Dist[v],v});
            }
        }
    }
}

int32_t main() {
    int N, M, u, v, w, source;
    cin >> N >> M;
    G = new vii[N+1];

    for(int i=0;i<M;++i){
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    source = 0;
    tugfa.assign(N,-1);
    Dijkstra(source,N);

    vi out;
    int it=N-1;
    while (it!=-1){
        out.push_back(it);
        it=tugfa[it];
    }

    if(out.size()==0 || out.back()!=0){
        cout << -1 << endl;
    }else{
        reverse(out.begin(),out.end());
        for (auto node : out)
            cout<< node+1 << " ";
    }

    return 0;
}
