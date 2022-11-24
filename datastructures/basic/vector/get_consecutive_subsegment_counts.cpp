#include "bits/stdc++.h"
#include "../../../debug.h"
using namespace std;

vector<int> get_subsegment_count(string s)
{
    int cnt = 1;
    int prev = s[0];
    vector<int> tmp;

    for(int i=0; i<s.size()-1; i++)
    {
        if(s[i+1] == prev)
            cnt++;
        else
        {
            tmp.push_back(cnt);
            cnt = 1;
        }
        prev = s[i+1];
    }
    tmp.push_back(cnt);
    return tmp;
}
