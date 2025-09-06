#include "../../../debug.h"



int main()
{
    string s = "HelloWorld";
    string pattern = "World";
    if(s.find(pattern) != string::npos)
    {
        cout << "Substring" << endl;
        auto it = s.find(pattern);
        cout << it << endl;
    }
    return 0;
}
