#include "../../../debug.h"

int main()
{
    unordered_map<char, int> hmap;
    unordered_map<int, int> cnt_map;

    vector<char> arr = {'a', 'g', 'd', 'c', 'e', 'b', 'f'};

    // Map the characters to their index
    int idx = 0;
    for(auto& elem: arr)
    {
        hmap[elem] = idx++;
    }

    for(auto& elem: arr)
    {
        cnt_map[elem] += 1;
    }

    return 0;
}
