#include "../../debug.h"


bool isLeap(int n)
{
    if(n % 100 == 0)
        if(n % 400 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    if (n % 4 == 0)
        return true;
    else
        return false;
}


int main()
{
    int year = 2020;
    bool result = isLeap(year);
    cout << "The result is: " << result;
    return 0;
}
