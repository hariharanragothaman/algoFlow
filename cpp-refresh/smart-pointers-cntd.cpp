//
// Created by hariharanragothaman on 4/20/25.
//
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct Point
{
    int id;
    explicit Point(int i) : id(i) {}
    ~Point() { std:: cout << "Bye " << id << "\n"; }
};

int main()
{
    vector<unique_ptr<Point>> v;
    v.reserve(1);
    for (int i=0; i<4; i++)
    {
        v.push_back(make_unique<Point>(i));
        cout << "Size: = " << v.size() << " Capacity = " << v.capacity() <<endl;
    }
}