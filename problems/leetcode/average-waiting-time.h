class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& A)
    {
        double n = static_cast<double>(A.size());
        double avg{};
        vector<double> B;
        double prev = A[0][0];
        double f{}, w{}, t{};

        for(int i=0; i<n; i++)
        {
            if(A[i][0] <= prev)
            {
                f = prev + A[i][1];
                w = f - A[i][0];
            }
            elsep
            {
                f = A[i][0] + A[i][1];
                w = f - A[i][0];
            }

            prev = f;
            B.push_back(w);
        }

        for(auto c: B)
            avg += c;

        return avg / n;
    }
};
