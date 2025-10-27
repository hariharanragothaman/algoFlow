class Solution {
public:
    int missingNumber(vector<int>& A)
    {
        int n = static_cast<int>(A.size());
        sort(A.begin(), A.end());

        bool flag = false;
        int ans{};
        for(int i=0; i<n; i++)
        {
            if (A[i] != i)
            {
                flag = true;
                ans = i;
                break;
            }
        }
        return (flag == true) ? ans : n;
    }
};
