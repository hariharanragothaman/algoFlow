#include "../../../debug.h"

int main()
{
    int R = 4;
    int C = 5;
    // Using the Fill Constructor
    vector<vector<int>> mat(R, vector<int>(C));

    // Can also use resize
    vector<vector<int>> A;
    A.resize(R, std::vector<int>(C));
    return 0;
}
