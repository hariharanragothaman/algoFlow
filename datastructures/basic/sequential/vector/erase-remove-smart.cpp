#include "../../../../debug.h"

int main()
{
    vector<int> A {1, 2, 3, 4, 5, 6, 7, 8};
    const auto new_end(remove(begin(A), end(A), 2));
    A.erase(new_end, end(A));
    print(A);
    cout << A.capacity() << " " << A.size() << endl;

    // Now how to do this in O(1) time
    vector<int> v {123, 456, 789, 100, 200};

}
