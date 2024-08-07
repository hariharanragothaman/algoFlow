#include "../../../debug.h"


int lengthOfLIS(vector<int>& nums)
{
    vector<int> rank;
    for(auto c: nums)
    {
        auto idx = lower_bound(rank.begin(), rank.end(), c) - rank.begin();
        if(idx == rank.size())
            rank.push_back(c);
        else
            rank[idx] = c;
    }
    return rank.size();

}

int main()
{
    return 0;
}
