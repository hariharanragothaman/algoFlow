#include <iostream>
using namespace std;

template<typename T>
T tmp_func(T a, T b)
{
    return a < b ? b : a;
}

template<typename T>
void print_container(vector<T> v)
{
    for(auto c: v)
    {
        cout << c << " ";
    }
    cout << endl;
}

int main()
{
    int hi = tmp_func(3, 7);
    double hd = tmp_func(2.3, 8.9);
    vector<int> A{1, 2, 3, 4, 5};
    print_container(A);
    vector<double> B{1.0, 2.0, 7.0, 11.0};
    print_container(B);

}
