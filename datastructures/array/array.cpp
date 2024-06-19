#include "bits/stdc++.h"
#include "../../debug.h"
using namespace std;

/*
 *  std::array is a homogeneous container of fixed length.
 *  The std::array combines the memory and runtime characteristic of a C array with the interface of std::vector
 *  This means in particular, the std::array knows its size.
 *  You can use std::array in the algorithms of the STL.
 *
 */

/*
 * You have to keep a few special rules in your mind to initialise a std::array.

    std::array<int, 10> arr                 The 10 elements are not initialised.
    std::array<int, 10> arr{}               The 10 elements are default initialised.
    std::array<int, 10> arr{1, 2, 3, 4, 5}  The remaining elements are default initialised.
    std::array supports three types of index access.
 *
 *
 */

/*
    std::array supports three types of index access.
        - arr[n];
        - arr.at(n);
        - std::get<n>(arr);
 *
 */

int main()
{
    std::array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto a: arr) std::cout << a << " " ;    // 1 2 3 4 5 6 7 8 9 10
    cout << "\n";

    double sum= accumulate(arr.begin(), arr.end(), 0);
    std::cout << sum << std::endl;               // 55

    double mean= sum / arr.size();
    std::cout << mean << std::endl;              // 5.5
    std::cout << (arr[0] == std::get<0>(arr));   // 1 (1 represents true)

    return 0;
}
