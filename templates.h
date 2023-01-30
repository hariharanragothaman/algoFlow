#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void print(vector<T> const &A)
{
    for (auto i: A)
        cout << i << ' ';
    cout << "\n";
}

template<typename T>
void quick_remove_at(vector<T>& A, int idx)
{
    if(idx < A.size())
    {
        A[idx] = move(A.back());
        A.pop_back();
    }
}

template<typename T>
void quick_remove_at(vector<T>& A, typename std::vector<T>::iterator it)
{
    if(it != end(A))
    {
        *it = move(A.back());
        A.pop_back();
    }
}
