#include "../debug.h"

vector<int> primeFactors(int n)
{
    vector<int> R;
    int c = 2;
    while(n > 1)
    {
        if(n % c == 0)
        {
            R.push_back(c);
            n /= c;
        }
        else
            c++;
    }
    return R;
}

int main()
{
    int n = 15;
    vector<int> result = primeFactors(n);
    for(auto c: result)
        cout << c <<  " ";
    cout << endl;
}
