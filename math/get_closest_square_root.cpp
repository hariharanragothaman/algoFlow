#include "bits/stdc++.h"
#include "../debug.h"
using namespace std;


int compute_square_root(int k)
{
    int left = 0;
    int right = k;

    while(left <= right)
    {
        int pivot = (left + right) / 2;
        if(pow(pivot, 2) <= k)
        {
            left = pivot + 1;
        }
        else
        {
            right = pivot - 1;
        }
    }
    return left - 1;
}

int main()
{
    int num = 300;
    // 300 - should give us 17 since 17^2 - 289
    int result = compute_square_root(num);
    cout << "The result is: " << result;
    return 0;
}
