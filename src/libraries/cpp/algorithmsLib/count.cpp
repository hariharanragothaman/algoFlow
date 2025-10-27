#include "../../../debug.h"

int main()
{
    /*
     *  Example-1 with string
     */
    string s = "helloworld";
    auto l_count = count(s.begin(), s.end(), 'l');
    cout << "The count of character 'l' is: " << l_count << endl;

    /*
     *  Example-2 with vector with slightly alternate syntax
     */
    vector<int> A = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    auto two_count = count(begin(A), end(A), 2);
    cout << "The count of 2 is: " << two_count << endl;
}
