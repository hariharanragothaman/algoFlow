#include "../../../../debug.h"

int get_longest_continuous_segment(string& s, const char& c)
{
    int n = s.size();
    int max_length = 0;
    int cnt = 0;

    for(int i=0; i<n; i++)
    {
        if(s[i] == c)
            cnt++;
        else if(s[i] != c)
            cnt = 0;
        max_length = max(max_length, cnt);
    }

    return max_length;
}

bool checkZeroOnes(string s)
{
    return get_longest_continuous_segment(s, '1') > get_longest_continuous_segment(s, '0');
}
