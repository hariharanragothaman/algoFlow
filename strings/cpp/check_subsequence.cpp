#include "bits/stdc++.h"
#include "../../debug.h"
using namespace std;

// Check if s is a subsequence of t

/*  
 * This is finding it from traversing s
 * You can also traverse from 't' and use find()
 * find() - if pos is passed - checks at pos, and values from pos
 */
bool isSubsequence(string s, string t)
{
    int sn = (int)s.size();
    int tn = (int)t.size();
    int j = 0;

    for(int i=0; i<sn; i++)
        if(s[i] == t[j])
            j++;

    return (j==tn);

    int main()
{
    string s = "elrld";
    string t = "HelloWorld";
    cout << isSubsequence(s, t);
    return 0;
}
