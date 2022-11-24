#include "bits/stdc++.h"
#include "../debug.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs)
    {
        int n = pairs.size();

        /*
        To find the eulerian path
        A graph has eulerian path only if:
        a. For each node indegree and outdegree is the same  (OR)
        b. For each node, indegree and outdegree is the same, except exactly 2 nodes.
            out[x] = in[x] + 1 (or) out[y] = in[y] - 1

        For condition a. when both indegree and outdegree is the same, all eulerian paths are also eulerian               circuits - where in starting index and ending index is the same...

        A node with out[i] == in[i] + 1 must be the starting point of an eulerian path if there exists one...
        */

        unordered_map<int, vector<int>> G;
        unordered_map<int, int> IN;
        unordered_map<int, int> OUT;

        for(auto c: pairs)
        {
            auto u = c[0];
            auto v = c[1];
            OUT[u]++;
            IN[v]++;
            G[u].push_back(v);
        }


        // Find the starting node..
        int start = -1;
        for(auto p: G)
        {
            int k = p.first;
            if(OUT[k] - IN[k] == 1)
            {
                start = k ;
                break;
            }
        }

        if(start == -1)
            start = G.begin()->first;

        // Now to actually perform the euler tour
        vector<int> ans;
        vector<vector<int>> result;
        deque<int> Q;
        Q.push_back(start);

        // Basically a modified DFS from the start location
        while(Q.size())
        {

            while(G[Q.back()].size())
            {
                int x = Q.back();
                Q.push_back(G[x].back());
                G[x].pop_back();
            }
            ans.push_back(Q.back());
            Q.pop_back();

        }

        reverse(ans.begin(), ans.end());

        for(int i=0; i<ans.size()-1; i++)
        {
            result.push_back({ans[i], ans[i+1]});
        }

        return result;
    }
};
