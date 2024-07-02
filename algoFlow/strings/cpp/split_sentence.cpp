#include "../../../debug.h"


int main()
{
    string s = "Hello this is awesome!";
    stringstream ss(s);
    string word;
    while(ss >> word)
    {
        cout << word << endl;
    }
}
