class Solution {
public:
    string reverseParentheses(string s)
    {
        vector<char> V;
        for(auto c: s)
        {
            if(c == ')')
            {
                string tmp{};
                while(V.back() != '(')
                {
                    tmp += V.back();
                    V.pop_back();
                }
                V.pop_back(); // Removing the '('

                for(auto c: tmp)
                    V.push_back(c);
            }
            else
            {
                V.push_back(c);
            }
        }
        string result{};
        for(auto c: V)
            result += c;
        return result;
    }
};
