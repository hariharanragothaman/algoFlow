#include "headers.h"


/*
 *
 * I feel this whole ranges and views library is to make C++ more like python. Hahaha
 * This is so much fun!
 *
 */


int main()
{
    vector<int> A = {1, 2, 3, 4, 5};

    // Get all the even numbers and multiply them by 2
    auto op =  A | std::views::filter([](int c) {return c % 2 == 0;})
                 | std::views::transform([](int c) {return c * 2; });

    for(auto c: op)
        cout << c << " ";
    cout << endl;

    // Learning how to use take()
    int n = A.size();
    auto first_3 = A | std::views::take(3);
    for(auto c: first_3)
        cout << c << " ";
    cout << endl;

    auto rev = A | std::views::reverse;
    for(auto c: rev)
        cout << c << " ";
    cout << endl;

    auto N = std::views::iota(0, 11);
    // A view does have an iterator
    vector<int> B(N.begin(), N.end());
    for(auto c: B)
        cout << c << " ";
    cout << endl;

    // Python style Zipped
    auto M = std::views::iota(0, 6);
    vector<int> C(M.begin(), M.end());
    vector<int> D(M.begin(), M.end());
    auto zipped = std::views::zip(C, D);
    for(auto [x, y]: zipped)
    {
        cout << x << " : " << y << endl;
    }

    //-----------------------------------------------------
    // Python style enumerate
    vector<int> E = {2, 4, 6, 8, 10};
    for(auto [i, val]: std::views::zip(std::views::iota(0), E))
    {
        cout << i << " : " << val << endl;
    }

    // Python style join

    vector<int> G = {"This", "is", "awesome"};
    auto joined = G | std::views::join_with(' ');
    for(auto c: joined)
        cout << c;





    return 0;
}
