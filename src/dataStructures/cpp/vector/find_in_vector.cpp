#include "../../../debug.h"

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};

    // Find the index of 3.
    auto idx = find(v1.begin(), v1.end(), 3) - v1.begin();
    cout << idx << endl;

    // We can also use distance()
    auto it = find(v1.begin(), v1.end(), 3);
    auto index = distance(v1.begin(), it);
    cout << index << endl;

    return 0;
}
