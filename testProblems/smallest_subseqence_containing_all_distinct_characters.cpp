#include "../debug.h"

class Solution {
public:
    string smallestSubsequence(string s)
    {
        /*
            smallest subsequence that contains all distinct characters of 's'
            Order must not be changed.
        */
        stack<char> ST;
        int n = (int) s.size();
        string res = "";
        unordered_map<char, int> last;

        for(int i=0; i<n; i++)
            last[s[i]] = i;

        unordered_map<char, int> visited;


        for(int i=0; i<n; i++)
        {
            if(visited[s[i]] > 0)
                continue;
            visited[s[i]] += 1;

            while(!ST.empty() and ST.top() > s[i] and i < last[ST.top()])
            {
                visited[ST.top()] = 0;
                ST.pop();
            }
            ST.push(s[i]);
        }

        while(!ST.empty())
        {
            res += ST.top();
            ST.pop();
        }

        reverse(res.begin(), res.end());
        return res;

    }
};
