#include <iostream>
using namespace std;

struct Point
{
    double x, y;
    Point(double x_, double y_)
    {
        cout << "Point (" << x_ << ", " << y_ << ")" << endl;
    }

    ~Point()
    {
        cout << "Bye" << endl;
    }
};


int main()
{
    Point p1{3.0, 4.0};
    Point p2 = {5.0, 6.0};
    Point arr[]{ {1, 2}, {3,4}}; // Pointer of arrays
}
