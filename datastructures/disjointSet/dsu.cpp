#include "../../debug.h"

class DSU
{
public:
    int nodes;
    int components;
    vector<int> parent;
    vector<int> sizes;

    DSU(int n)
    {
        nodes = n;
        /*
         *  For each node, there is no parent initially
         *  All the component sizes are of size 1
         */
        parent = vector<int>(n, -1);
        sizes = vector<int>(n, 1);
        components = n;

    }

    int get(int node)
    {
        return parent[node] < 0 ? node : parent[node] = get(parent[node]);
    }

    bool same_set(int node1, int node2)
    {
        return get(node1) == get(node2);
    }

    int size(int node)
    {
        return sizes[get(node)];
    }

    bool unite(int node1, int node2)
    {
        /*
         *  There are many strategies to group nodes together.
         *  By Rank, By Path Compression -
         *  Mostly depending on the question; this has to be modified.
         */

        node1 = get(node1);
        node2 = get(node2);
        if(node1 == node2)
            return false;
        else if (node1 != node2)
        {
            if(sizes[node2] < sizes[node1])
                swap(node1, node2);
            parent[node2] = node1;
            sizes[node1] += sizes[node2];
            components -= 1;
        }
        return true;
    }

    int get_components()
    {
        return components;
    }
};
