#include "../../../debug.h"

class A
{
private:
    int a, b;

public:
    A(int x, int y)
    {
        a = x;
        b = y;
    }
    int multiply();
};

int A::multiply()
{
    return a * b;
}

int main()
{
    A obj(5, 6);
    cout << obj.multiply() << endl;
}
