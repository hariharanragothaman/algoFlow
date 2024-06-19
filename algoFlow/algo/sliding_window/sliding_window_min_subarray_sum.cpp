#include "../../../debug.h"
using namespace std;

/*
 *  Find shortest sub-array, that has value >= m
 */

void minSubArraySum(vector<int> A, int n, int m)
{
    int left = 0;
    int right = 0;
    int csum = 0;
    int ans = INT_MAX;

    while (right < n)
    {
        csum += A[right];

        while( csum >= m && left <= right)
        {
            ans  = min(ans, right-left+1);
            csum -= A[left];
            left += 1;
        }

        right += 1;
    }
    if(ans != INT_MAX)
        cout << ans << endl;
    else
        cout << -1 << endl;
}

int main()
{
    return 0;
}
