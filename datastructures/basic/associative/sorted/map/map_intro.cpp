#include "bits/stdc++.h"
#include "../../../../../debug.h"
using namespace std;

/*
 *  Map in C++ is by default sorted by key.
 */

int main()
{
    string s = "codeforces";
    map<char, int> hmap;

    for(auto&it : s)
        hmap[it] += 1;

    // Printing the map
    for(auto it= hmap.begin(); it != hmap.end(); it++)
        cout << it->first << it->second << endl;

    return 0;
}
