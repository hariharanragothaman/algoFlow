//
// Created by Hariharan Ragothaman on 4/27/25.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template<typename T>
void print_vec(vector<T> V)
{
    for(auto c: V)
    {
        cout << c << " ";
    }
    cout << endl;
}


vector<int> twoSum(vector<int>& A, int target)
{
    print_vec(A);
    int n = A.size();

    unordered_map<int, int> H;
    for(int i=0; i<n; i++)
    {
        H[A[i]] = i;
    }
    for(int i=0; i<n; i++)
    {
        int tmp = target - A[i];
        auto idx = H.find(tmp);
        if(H.find(tmp) != H.end() && idx->second != i)
        {
            return {idx->second, i};
        }
    }
    return {-1, -1};
}

int main()
{
    vector<int> A = {2, 7, 11, 15};
    int T = 9;
    auto result = twoSum(A, T);
    print_vec(result);
}
