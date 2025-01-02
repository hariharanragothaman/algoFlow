#include "../../../debug.h"

vector<int> prefixSum(vector<int> A)
{
    int n = A.size();
    vector<int> PS(n+1, 0);
    for(int i=1; i< PS.size(); i++)
    {
        PS[i] = PS[i-1] + A[i-1];
    }
    return A
}

int main()
{
    vector<int> T = {1, 2, 3, 4, 5};
    vector<int> PS_T = prefixSum(T);
    // We are assuming zero-indexing, hence to find sum between start and end
    int start  = 2, end = 4;
    int ans = PS_T[end+1] - PS_T[start];
    cout << "The answer is: " << ans << endl;
}
