#include "bits/stdc++.h"
#include "../debug.h"
using namespace std;

#include "../headers.h"


int main()
{
    string s = "Success";
    int n = s.size();
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            string substring = s.substr(i, (j-i)+1);
            cout << substring << endl;
        }
    }

    return 0;
}
