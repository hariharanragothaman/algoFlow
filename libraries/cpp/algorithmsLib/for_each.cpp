#include "../../../debug.h"

/*
 *  1. A few key points to remember - you can't simply modify the vector in-place.
 *     Not exactly the same as list comprehension.
 *  2.
 */

int main()
{
    vector<int> A = {1, 2, 3, 4, 5};
    auto print = [](int n)
    {
        cout << n << " ";
    };

    /*
     * Example - 1 - Incrementing all the values by 1
     */
    auto increment = [](int &n)
    {
        n++;
    };
    for_each(A.begin(), A.end(), increment);
    for_each(A.begin(), A.end(), print); cout << endl;

    /*
     *  Example -2 Apply some condition for it - like if it's even?
     */
    auto check_odd = [](int &n)
    {
        return n & 1;
    };
    for_each(A.begin(), A.end(), check_odd);
    for_each(A.begin(), A.end(), print); cout << endl;

}
