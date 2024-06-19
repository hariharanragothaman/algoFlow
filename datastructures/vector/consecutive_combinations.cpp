#include "../../debug.h"

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    for(int i = 0; i < v1.size() -1; i++)
        cout << v1[i] << v1[i+1] << endl;
    return 0;
}
