#include "../../../debug.h"

bool startsWith(string s, string t)
{
    return (t.substr(0, s.size()) == s);
}
bool endsWith(string s, string t)
{
    if(s.size() > t.size()) return false;
    return t.compare(t.size() - s.size(), s.size(), s) == 0;
}

int main()
{
    return 0;
}
