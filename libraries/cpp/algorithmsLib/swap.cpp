#include "bits/stdc++.h"
#include "../../../debug.h"
using namespace std;


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
