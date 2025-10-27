#include "../../../debug.h"
using namespace std;

int main()
{
    vector<int> A = {1, 2, 3, 4 ,5};
    int n = A.size();
    // Creating the difference array
    vector<int> D(2*n, 0);
    for(int i=0; i<n;i++)
    {
        if(i==0)
        {
            D[i] = A[i];
        }
        else
        {
            D[i] = A[i] - A[i-1];
        }
    }
    // Assuming zero-indexing
    int L = 1;
    int R = 3;
    int value = 5;

    D[L] += value;
    D[R+1] -= value;

    // Updating the original array
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            A[i] = D[i];
        }
        else
        {
            A[i] = D[i] + A[i-1];
        }
    }

    auto print = [](int &n) {cout << n << " ";};
    for_each(A.begin(), A.end(), print);

}
