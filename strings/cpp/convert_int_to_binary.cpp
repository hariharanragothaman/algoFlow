#include "bits/stdc++.h"
#include "../../debug.h"
using namespace std;

int main()
{
    int n = 7;
    // Here 32 denotes the total bits
    string str = bitset<32>(n).to_string();
    str.erase(0, str.find_first_not_of('0'));
}
