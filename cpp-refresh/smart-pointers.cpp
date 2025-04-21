//
// Created by hariharanragothaman on 4/20/25.
//


#include <iostream>
#include <memory>
using namespace std;

struct Point
{
  double x, y;
  Point(double xx, double yy): x(xx), y(yy) {}
  ~Point() { cout << "Bye! (" << x << ", " << y << ")" << " " << this << endl; }
};

int main()
{
  // ---------unique pointer: one and only owner -------------
  unique_ptr<Point> p1 = make_unique<Point>(1.0, 1.0);
  Point *raw = p1.get();
  cout << raw->x << ", " << raw->y << endl;

  // unique_ptr<Point> p2 = p1; - This will give compilation error - copy is disallowed
  unique_ptr<Point> p2 = move(p1);
  if (!p1)
  {
    cout << "p1 is empty after move" << endl;
  }

  // ---- shared_ptr: reference counted, many owners
  auto sp1 = make_shared<Point>(2.0, 2.0);
  shared_ptr<Point> sp2 = sp1;
  cout << "sp1 use_count = " << sp1.use_count() << endl;

  sp1.reset(); // reset count - decrements count
  cout << "sp2 still owns? " << std::boolalpha << static_cast<bool>(sp2) << endl;
}