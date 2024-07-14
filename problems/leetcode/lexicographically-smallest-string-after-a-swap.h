/*
 *  Same parity - XOR is even
 *  Different parity XOR is odd
 */

class Solution
{
public:
    string getSmallestString(string s)
    {
        int n = static_cast<int>(s.size());
        for(int i=0; i<n-1; i++)
        {
            if(s[i] > s[i+1])
            {
                if((s[i] ^ s[i+1]) % 2 == 0 )
                {
                    swap(s[i], s[i+1]);
                    break;
                }
            }
        }
        return s;
    }
};
