#include "../../../debug.h"
/*
 *  swap() internally used move()
 */

template <typename T>
inline void swap(T& a, T& b)
{
    T tmp(std::move(a));
    a= std::move(b);
    b= std::move(tmp);
}

int main()
{
    return 0;
}
