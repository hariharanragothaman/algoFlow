class Solution {
public:
    bool canPlaceFlowers(vector<int>& A, int n)
    {
        int sz = static_cast<int>(A.size());
        printVector(A);
        int cnt{};

        /* Edge cases */
        if(n == 0)
        {
            return true;
        }
        if(sz == 1)
        {
            return (A[0] == 0 and n == 1) ? true: false;
        }

        /* Greedily Adding in the beginning */
        if(A[0] == 0 and A[1] == 0 and cnt < n)
        {
            A[0] = 1;
            cnt++;
        }

        /* Checking if we can place in the middle */
        for(int i=2; i<sz-1; i++)
        {
            if(A[i-1] == 0 && A[i+1] == 0 &&  A[i] == 0 and cnt < n)
            {
                cnt++;
                A[i] = 1;
            }
        }

        /* Greedily adding in the end */
        if(A[sz-1] == 0 and A[sz-2] == 0 and cnt < n)
        {
            A[sz-1] = 1;
            cnt++;
        }
        return (cnt == n) ? true: false;
    }
};
