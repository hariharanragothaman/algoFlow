#include "../../debug.h"
using namespace std;

void minSubArraySum(vector<int> A, int n)
{
    int left = 0;
    int right = 0;
    int csum = 0;
    int maxSum = A[left];

    while (right < n)
    {
        csum += A[right];
        maxSum = max(maxSum, csum);
        while( csum < 0 && left <= right)
        {
            csum -= A[left];
            left += 1;
        }

        right += 1;
    }

    cout << maxSum << endl;
}
