#include "../../debug.h"

// Covers fundamental ideas about how to represent graphs in C++

int main()
{
    // This is one way to represent an adjacency list
    // A convenient way to store the adjacency lists is to declare an array of vectors
    int n = 5;
    vector<int> G[n];

    int A[5];
    // This is another way?
    vector<vector<int>>G;
    G[0].push_back(5);

    // Technically, we can also have an unordered map?
    unordered_map<int, vector<int>> H;
    // in the vector, the 'int' key by default is the index itself.

    // For a weighted graph? - since it has the weight component also.
    vector<vector<pair<int, int>> G;

}
