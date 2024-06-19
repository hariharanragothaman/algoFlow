#include "../../../debug.h"
using namespace std;

/*
 * The prefix function for this string is defined as
 * the length of the longest proper prefix of the substring which is also a suffix.
 */

vector<int> kmp(string s)
{
    int n = (int) s.size();
    vector<int> P(n, 0);
    for(int i=0; i<n; i++)
        for(int k=0; k<=i; k++)
            if(s.substr(0, k) == s.substr(i-k+1, k))
                P[i] = k;
    return P;
}

int main()
{
    string s = "abddab";
    vector<int> res = kmp(s);
    print(res);
}
