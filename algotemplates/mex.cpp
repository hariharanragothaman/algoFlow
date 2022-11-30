#include "../debug.h"
using namespace std;

/*
 * Given an array A of size N; find the minimal element that is not present in the array
 * The element is equal or greater than zero.
 */


int mex(vector<int> a)
{
    set<int> b(a.begin(), a.end());
    for (int i=0; ; ++i)
        if (!b.count(i))
            return i;
}

int mex (const vector<int> & a)
{
    static bool used[D+1] = { 0 };
    int c = (int) a.size();

    for (int i=0; i<c; ++i)
        if (a[i] <= D)
            used[a[i]] = true;

    int result;
    for (int i=0; ; ++i)
        if (!used[i])
        {
            result = i;
            break;
        }

    for (int i=0; i<c; ++i)
        if (a[i] <= D)
            used[a[i]] = false;

    return result;
}
