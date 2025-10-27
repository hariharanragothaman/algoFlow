#include "../../debug.h"

class Solution {
public:
    bool isValid(string s)
    {
        vector<char> open = {'(','{', '[' };
        vector<char> close = {')', '}', ']' };
        vector<char> stack;

        for(auto c : s)
        {
            if(find(open.begin(), open.end(), c) != open.end())
            {
                stack.push_back(c);
            }
            else if(find(close.begin(), close.end(), c) != close.end())
            {
                auto idx = find(close.begin(), close.end(), c) - close.begin();

                if(!stack.empty() and stack.back() == open[idx])
                {
                    stack.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }

        return (!stack.empty()) ? false: true;
    }
};
