class Solution {
public:
    int helper(vector<int>&A, int k)
    {
        int n = static_cast<int>(A.size());
        int l{}, ans{};
        unordered_map<int, int> H;

        for(int r=0; r<n; r++)
        {
            H[A[r]]++;

            while(H.size() > k)
            {
                H[A[l]] -= 1;
                if(H[A[l]] == 0)
                    H.erase(A[l]);
                l++;
            }

            ans += (r-l+1);   // Calcuate subarrays
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& A, int k)
    {
        return helper(A, k) - helper(A, k-1);
    }
};
