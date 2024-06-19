#include "bits/stdc++.h"
#include "../../../debug.h"
using namespace std;


bool checkPalindrome(string s)
{
    return s == string(s.rbegin(), s.rend()) ? true : false;
}

bool check_palindrome2(string s)
{
    int n = (int) s.size();
    for(int i=0; i < n/2; i++)
    {
        if(s[i] != s[n-i+1])
            return false;
    }
    return true;
}

int main()
{
    string s = "malayalam";
    bool result = checkPalindrome(s);
    cout << result << endl;
}
