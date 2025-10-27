#include "../headers.h"

int main()
{
    vector<int> A = {1, 2, 3, 4, 5};
    int n = A.size();
    cout << "Total no of sub arrays = " << n * (n-1) / 2 << endl;
    /*
     *  Number of times an idx appears is a cartesian product of
     *   i   * (n-i+1)
     *   left   right
     */
    return 0;
}
