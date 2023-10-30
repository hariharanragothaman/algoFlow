#include "bits/stdc++.h"
#include "../../debug.h"
using namespace std;

void postOrderTraversal( map<int, vector<int>>& graph, int n)
{
    deque<int> q;
    int root = 1;
    q.emplace_back(root);
    int node;

    vector<int> res_tmp;
    vector<int> postorder;

    while (q.size() > 0)
    {
        node = q.back();
        q.pop_back();
        res_tmp.push_back(node);
        if (graph[node].size() > 0)
        {
            for (auto c: graph[node])
                q.emplace_back(c);
        }
    }

    while (res_tmp.size() > 0)
    {
        postorder.emplace_back(res_tmp.back());
        res_tmp.pop_back();
    }
}

int main()
{
    return 0;
}
