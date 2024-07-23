#include "../../../debug.h"

struct Compare
{
    bool operator()(pair<int,int> a, pair<int, int> b)
    {
        if(a.second != b.second)
        {
            return a.second < b.second;
        }
        else
        {
            return a.first > b.first;
        }
        return 0;
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& A)
    {
        unordered_map<int, int> H;
        for(auto c: A)
            H[c]++;

        /*
        vector<pair<int, int>> B; 

        for(auto k: H)
            B.push_back({k.first, k.second}); 
        sort(B.begin(), B.end(), Compare());
        vector<int> ans; 
        for(auto c: B) 
        {
            for(int i=0; i<c.second; i++)
                ans.push_back(c.first);
        }
        return ans;
        */

        /*
        Method-2

        auto lambda_sort = [&](int a, int b) {return H[a] == H[b] ? a > b : H[a] < H[b]; };
        sort(A.begin(), A.end(), lambda_sort);

        */

        /* Method-3 */
        sort(A.begin(), A.end(), [&](int a, int b)
        {
            if (H[a] != H[b])
                return H[a] < H[b];
            return a > b;
        });


        return A;
    }
};
