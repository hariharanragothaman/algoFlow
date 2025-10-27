
/*
 * Copy the array to itself, length becomes 2*n; parse till n
 *
 */

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int>& colors)
    {
        int n = colors.size();
        for(int i=0;i<n;i++)
            colors.push_back(colors[i]);

        int ans = 0;
        for(int i=0;i<n;i++)
            if(colors[i] == colors[i+2] and colors[i] != colors[i+1])
                ans++;
        return ans;
    }
};
