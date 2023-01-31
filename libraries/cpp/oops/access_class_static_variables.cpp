#include "../../../debug.h"

class Test
{

    static int x;
public:
    static int y;

    void func(int x)
    {
        cout << "The value of static x is: " << Test::x << endl;
        cout << "The value of local x is: " << x << endl;
    }
};

// Static members can directly be accessed without creating objects
int Test::x = 1;
int Test::y = 2;

int main()
{
    Test obj;
    int x = 3;
    obj.func(x);
    return 0;
}
