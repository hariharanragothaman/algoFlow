class Solution {
public:
    int findTheWinner(int n, int k)
    {
        deque<int> C;
        for(int i=1; i<=n; i++)
        {
            C.push_back(i);
        }

        while(C.size() > 1)
        {
            for(int i=1; i<k; i++)
            {
                auto tmp = C.front();
                C.push_back(tmp);
                C.pop_front();
            }

            C.pop_front();
        }

        return C.front();
    }
};
