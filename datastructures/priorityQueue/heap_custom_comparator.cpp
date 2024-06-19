#include "../../debug.h"

struct Compare
{
    bool operator()(const pair<int, int> a, const pair<int, int> b)
    {
        if(a.first == b.first)
            return a.second > b.second;

        return a.first < b.first;
    }
};

int main()
{
    vector<pair<int, int>> A = {{1, 2}, {3, 4}};
    int n = A.size();
    // data-type, container, Comparator function
    priority_queue< pair<int, int>, vector<pair<int, int>>, Compare> B;
}
