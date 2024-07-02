#include "../../../debug.h"


// Modify the functor here to for reverse=True functionality
bool sort_by_value(const pair<char, int> &a, const pair<char, int> &b)
{
    return (a.second < b.second);
}

// Here sort map by value, but if the values are the same
// sort map by keys in descending order
// An example to write custom comparator
bool sort_by_value(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.second == b.second)
    {
        return (a.first > b.first);
    }
    else
    {
        return (a.second < b.second);
    }
}


// Another example -
// vector of vectors we want to sort by the second value
bool sort_by_value(const vector<int>& a, const vector<int>& b)
{
    return a[1] > b[1];
}

int main()
{
    vector<char> arr = {'a', 'g', 'd', 'c', 'e', 'b', 'f', 'a', 'c', 'e'};
    unordered_map<char, int> hmap;
    for(auto& elem: arr)
    {
        hmap[elem] += 1;
    }

    vector<pair<char, int>> vec;
    for(auto& elem: hmap)
    {
        vec.push_back(make_pair(elem.first, elem.second));
    }

    sort(vec.begin(), vec.end(), sort_by_value);

    cout << "Printing pairs after sorting by value" << endl;
    for(auto& it: vec)
    {
        cout << it.first << it.second << endl;
    }

    return 0;
}
