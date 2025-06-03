//
// Created by Hariharan Ragothaman on 4/27/25.
//

#include <iostream>
using namespace std;

template<size_t N>
struct FixedBuffer {
    array<char, N> data;
};

int main()
{
    FixedBuffer<1024> buff;
}
