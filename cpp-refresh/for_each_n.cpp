#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> A{1, 2, 3, 4, 5};
    auto print = [](int& v){cout << v;  };
    for_each(A.begin(), A.end(), print);
    auto multiply_by_two = [](int& v){  v *= 2;  };

    // Start from origin and till origin + 2, origin starts at zero
    for_each_n(A.begin(), 3, multiply_by_two);
    cout << endl;
    for_each(A.begin(), A.end(), print);

    return 0;
}
