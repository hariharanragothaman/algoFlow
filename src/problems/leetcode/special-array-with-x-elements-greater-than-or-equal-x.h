#include "../../debug.h"


/*
 *  Question: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x
 *
 *  You are given an array nums of non-negative integers.
 *  nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.
 *  Notice that x does not have to be an element in nums.
 *  Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.
 *
 *
 */


/*
    LOGIC:

    1. We need to find out if there is a value, such that:
       number of values greater than (or) equal to value - is equal to value.

    Let's sort the array in reverse.
    Once the array is sorted in reverse order.

    As we parse the vector from left to right.

    Each index - left increase, and it tells, for the value in A[left];
    how many values are greater than or rqual to it.

    // Monotonicity Check
    Consider the scenario where A[pivot] <= pivot; then?
        value is lesser, than number of values greater than or equal to value
    Hence we shift left and right appropriately.
*/

class Solution 
{
public:
    int specialArray(vector<int>& A)
    {
        sort(A.begin(), A.end(), greater<int>());

        for(auto c: A)
            cout << c << " ";
        cout << endl;

        int n = A.size();
        int left = 0, right = n-1;
        while(left <= right)
        {
            int pivot = left + (right - left) / 2;
            cout << "The pivot is: " << pivot << endl;
            if(A[pivot] > pivot)
                left = pivot + 1;
            else
                right = pivot - 1;
        }
        if(left < n and left == A[left])
            return -1;
        else
            return left;
    }
};
