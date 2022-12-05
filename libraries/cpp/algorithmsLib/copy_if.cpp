#include "../../../debug.h"

/*
 *  Copy to another vector if the 'predicate' is true
 */

int main()
{
    vector<int> A = {1, 4, 0, 2, 0, 0};
    vector<int> B;
    copy_if(A.begin(), A.end(), back_inserter(B), [](int i){ return i > 0;});
}
