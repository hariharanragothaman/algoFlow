#include "bits/stdc++.h"
#include "../../../../debug.h"
using namespace std;

int main()
{
    vector<char> arr = {'a', 'g', 'd', 'c', 'e', 'b', 'f'};
    unordered_map<char, int> hmap;
    int idx = 0;
    for(auto& elem: arr)
        hmap[elem] = idx++;

    // Checking if the hashmap contains a specific key
    if (hmap.find('e') != hmap.end())
        cout << "Yaay the key exists\n";

}
