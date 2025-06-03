#include <iostream>
using namespace std;

template<class T>
class Vector2 {
    T x_, y_;
public:
    Vector2(T x = {}, T y = {}): x_(x), y_(y) {}
};

template<typename T>
constexpr T min_abs(T a, T b)
{
    return abs(a) < abs(b) ? abs(a) : abs(b);
}

int main()
{

}
