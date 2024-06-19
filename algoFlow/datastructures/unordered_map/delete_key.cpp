#include "../../../debug.h"

int main()
{
    unordered_map<char, int> H;
    string s = "abcdef";
    for(auto c : s)
        H[c]++;
    for(auto c: H)
    {
        cout << c.first << " " << c.second << endl;
    }
    // Deleting 'f'
    H.erase('f');
    cout << "Printing after deleting" << endl;
    for(auto c: H)
    {
        cout << c.first << " " << c.second << endl;
    }
}
