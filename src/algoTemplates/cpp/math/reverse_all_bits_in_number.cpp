#include "../../debug.h"

/*
To clear any particular set of bits, you can use bitwise AND with the complement of a number that has 1s in those places.
b &= ~0xFFFF; // Clear lower 16 bits.
If you wanted to set those bits, you could instead use a bitwise OR with a number that has those bits set:
b |= 0xFFFF; // Set lower 16 bits.
And, if you wanted to flip those bits, you could use a bitwise XOR with a number that has those bits set:
b ^= 0xFFFF; // Flip lower 16 bits.

*/

/*

1 ^ x => ~x
0 ^ x => x
Step 1: Create a mask with upper 16 bits are set and lower 16 bits are cleared.
Step 2: XOR input and mask.
Int invertUpper16 (int x) {
int mask = ~((1 0000_0000_0000_0001_0000_0000_0000_0000
When we subtract 1 from 1 0000_0000_0000_0000_1111_1111_1111_1111
When we negate (1 1111_1111_1111_1111_0000_0000_0000_0000;

*/

int invertUpper16(int x)
{
    int size = 16;
    int mask = ~((1 << (size+1))-1);
    x ^= mask;
    cout << bitset<32>(x).to_string() << endl;
    return x;

}


int main()
{
    int result = invertUpper16(5);
    cout << "The ans is:" << result << endl;
    return 0;
}
