#include "../headers.h"

void fibonacci(int n)
{
    vector<int> v = {0,1};
    int temp = 0;

    for(int i=2; i<n; i++)
    {
        temp = v[i-1] + v[i-2];
        v.push_back(temp);
    }

    for(auto it: v)
    {
        cout << it << " ";
    }
}

int main()
{
    int n = 6;
    fibonacci(n);
}
