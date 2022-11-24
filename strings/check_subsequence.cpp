#include "bits/stdc++.h"
#include "../debug.h"
using namespace std;

// Check if s is a subsequence of t
bool isSubsequence(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int j = 0;
    for(int i=0; i<n; i++)
    {
        if(s[j]==t[i])
            j++;
    }
    return j==m;
}

int main()
{
    string s = "elrld";
    string t = "HelloWorld";
    cout << isSubsequence(s, t);
    return 0;
}
