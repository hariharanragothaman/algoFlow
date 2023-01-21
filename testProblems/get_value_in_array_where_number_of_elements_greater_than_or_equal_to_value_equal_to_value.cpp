#include "bits/stdc++.h"
using namespace std; 

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
