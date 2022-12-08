#include "../../../debug.h"

/*
 *  1. A few key points to remember - you can't simply modify the vector in-place.
 *     Not exactly the same as list comprehension.
 *  2.
 */

int main()
{
    vector<int> A = {1, 2, 3, 4, 5};
    auto print = [](int n)
    {
        cout << n << " ";
    };

    /*
     * Example - 1 - Incrementing all the values by 1
     */
    auto increment = [](int &n)
    {
        n++;
    };
    for_each(A.begin(), A.end(), increment);
    for_each(A.begin(), A.end(), print); cout << endl;

    /*
     *  Example -2 Apply some condition for it - like if it's even?
     */
    auto check_odd = [](int &n)
    {
        n = n & 1 ? 1: 0;
    };
    for_each(A.begin(), A.end(), check_odd);
    for_each(A.begin(), A.end(), print); cout << endl;

    /*
     *  Now let's try incrementing an external variable?
     */
    int sum = 0;
    /*
     *  We need to unpack what is happening in this lambda function here.
     *
     *  A lambda is just a another way to make a class and provide an operator() for it.
     *  The [] part of the lambda describes the member variables and whether they are captured by reference or value
     *  The () part of the lambda is the parameter list for the operator() and the {} part is the body of that function.
     *  The mutable part tells the compiler to make the operator() non const as it is const by default.
     *  For more - Refer lambda_basics.cpp
     *
     */
    auto add = [&sum](int n) mutable
    {
        sum += n;
    };
    for_each(A.begin(), A.end(), add);
    cout << "The value of sum is: " << sum << endl;

    /*
     * Another test,
     * Let's say I have a vector of pairs;
     * and I want to filter out the the pairs second, if it satisifies a specific predicate?
     * Let's try to write for this.
     */

    vector<pair<int, int>> T;
    for(int i=0; i<=5; i++)
        T.push_back(make_pair(i, i*2));

    vector<int> result;

    auto custom_lambda = [&result](pair<int, int> c) mutable
    {
        cout << c.first << " " << c.second << endl;
        if(c.second % 2 == 0)
        {
            result.push_back(c.second);
        }
    };
    for_each(T.begin(), T.end(), custom_lambda);
    // Finally printing the result
    cout << "Printing the result vector " << endl;
    for_each(result.begin(), result.end(), print);
    cout << endl;

}
