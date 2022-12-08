#include "../../../debug.h"

int main()
{
    /*
     *  Example-1 with string
     */
    string s = "helloworldHELLO";
    auto upper_count = [](char &ch)
    {
        return isupper(ch);
    };
    auto cnt= count_if(s.begin(), s.end(), upper_count);
    cout << "The number of upper-case characters is: " << cnt << endl;

    /*
     *  Example-2 with vector with slightly alternate syntax
     */
    vector<int> A = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    auto predicate = [](auto c)
    {
        return c == 2;
    };
    auto cnt2 = count_if(A.begin(), A.end(), predicate);
    cout << "The count is: " << cnt2 << endl;
}
