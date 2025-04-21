//
// Created by hariharanragothaman on 4/20/25.
//

#include <iostream>
#include <ostream>
#include <memory>
using namespace std;

struct Point
{
    double x, y;   // This is by default public

    // Constructor (just os you can see what runs first)
    Point(double x_, double y_) : x(x_), y(y_)
    {
        cout << "Point(" << x_ << ", " << y_ << ")" << endl;
    }

    ~Point()
    {
        cout << "Bye!" << endl;
    }
};

int main()
{
    cout << "-------------- Beginning CPP Refresh ----------------" << endl;

    // Stack (automatic object) -- lives until 'main' leaves scope.
    cout << "==== stack object ======" << endl;
    Point p1{3.5, 4.2};  // direct list initialization
    cout << p1.x << " " << p1.y << endl;

    // **Heap (dynamic) object using raw - 'new' - remember to delete
    cout << "==== raw-new object =====" << endl;
    Point* p2 = new Poi nt(1.0, 2.0);
    cout << p2->x << ", " << p2->y << endl;
    delete p2;

    // Heap object with a smart pointer -- preferred modern C++ style
    std::cout << "\n=== smart pointer object ===\n";
    auto p3 = make_unique<Point>(3.5, 4.0);
    cout << p3->x << ", " << p3->y << endl;

    cout << "=== leaving main() -------" << endl;
}
