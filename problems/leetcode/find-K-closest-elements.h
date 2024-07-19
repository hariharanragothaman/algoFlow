struct Compare
{
    bool operator()(vector<int> A, vector<int> B)
    {
        if(abs(A[0]-A[1]) > abs(B[0]-B[1]))
        {
            return true;
        }
        else if(A[0] > B[0] and abs(A[0]-A[1]) == abs(B[0]-B[1]))
        {
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x)
    {
        priority_queue<vector<int>, vector<vector<int>>, Compare> PQ;
        int n = static_cast<int>(A.size());

        for(int i=0; i<n; i++)
        {
            PQ.push({A[i], x});
        }

        vector<int> ans{};

        while(k > 0)
        {
            auto T = PQ.top();
            PQ.pop();
            ans.push_back(T[0]);
            k--;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
