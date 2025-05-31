/* vector_tutorial.cpp — An annotated walkthrough of common std::vector operations */
/* Compile with: g++ -std=c++20 -Wall -Wextra -pedantic vector_tutorial.cpp -o vector_tutorial */

#include <algorithm>   /* std::for_each, std::swap */
#include <iostream>    /* std::cout */
#include <vector>      /* std::vector */
#include <ranges>      /* std::views::reverse (C++20) */
#include <string_view> /* std::string_view for labels */

using namespace std;

/* -----------------------------------------------------------------------------
   A small helper that prints any container whose elements are stream‑insertable.
   Passing the container by const reference avoids an unnecessary copy.
----------------------------------------------------------------------------- */

template <typename Container>
void print(const Container& c, std::string_view label = {})
{
    if (!label.empty()) std::cout << label << ": ";
    for (const auto& elem : c) std::cout << elem << ' ';
    std::cout << '\n';
}

auto print2 = [](const int& c) { cout << c << " "; };

template<typename T>
void print_vector(vector<T> A)
{
    for (auto c : A) cout << c << " ";
    cout << endl;
}

/* main() function begins() */
int main()
{
    /* Construction & basic element access */
    std::vector<int> A{1, 2, 3, 4, 5};
    print(A, "Initial vector");

    /* push_back vs. emplace_back */
    A.push_back(6);      /* copies/moves 6 into the vector */
    A.emplace_back(7);   /* constructs 7 in‑place (no extra move) */
    print(A, "After push_back / emplace_back");

    /* pop_back removes the last element */
    A.pop_back();
    print(A, "After pop_back");

    /* Create n copies of a value with assign */
    std::vector<int> zeros;
    zeros.assign(5, 0);          /* equivalent to Python’s [0] * 5 */
    print(zeros, "zeros");

    /* Reverse iteration (C++20 views) */
    std::cout << "Reverse v: ";
    for (int x : A | std::views::reverse) std::cout << x << ' ';
    std::cout << "\n\n";

    for_each(A.rbegin(), A.rend(), print2); /* Another style of printing in reverse */
    cout << endl;

    /* Capacity helpers */
    std::cout << std::boolalpha
              << "A.empty()  -> " << A.empty() << '\n'
              << "A.size()   -> " << A.size()  << "\n\n";

    /* clear removes all elements but keeps capacity */
    std::vector<int> C{1, 2, 3, 4, 5};
    print(C, "C before clear");
    C.clear();
    print(C, "C after clear");
    std::cout << "C.size() -> " << C.size() << "\n\n";

    /* insert: place a value before an iterator position */
    std::vector<int> D{1, 2, 3, 4, 5};
    D.insert(std::next(D.begin(), 2), 11);   /* insert 11 at index 2 */
    print(D, "d after insert");

    /* erase removes a single element or a half‑open range [first, last) */
    std::vector<int> Z{1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(Z, "z before erase");
    Z.erase(std::next(Z.begin(), 2), std::next(Z.begin(), 5)); /* erase 3..5 */
    print(Z, "z after erase");

    /* swap exchanges contents in O(1) */
    std::vector<int> A1{1, 2, 3}, B1{4, 5};
    cout << endl;
    std::cout << "Before swap:\n";
    print(A1, "A1");
    print(B1, "B1");

    std::swap(A1, B1);   /* std::vector::swap(a, b) works too */

    std::cout << "After swap:\n";
    print(A1, "A1");
    print(B1, "B1");
    cout << endl;

    /********* SEARCH OPERATIONS **************/
    vector<int> VV {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    /* all_of */
    auto check_even = [](int c){return c % 2 == 0;};
    bool all_of_flag = all_of(VV.begin(), VV.end(), check_even);
    cout << "Are all numbers even? " << all_of_flag << endl;

    /* any_of */
    bool any_of_flag = any_of(VV.begin(), VV.end(), check_even);
    cout << "Any of the numbers even? " << any_of_flag << endl;

    auto equals_to_zero = [](int c) {return c == 0; };
    bool none_of_flag = none_of(VV.begin(), VV.end(), equals_to_zero);
    cout << "Are any numbers equal to zero? " << none_of_flag << endl;

    /* find */
    int needle = 7;
    vector<int> haystack = {7, 5, 2, 1, 6};
    if(find(haystack.begin(), haystack.end(), needle) == haystack.end())
        cout << "Needle is not there in haystack" << endl;
    else
        cout << "Needle is there in haystack" << endl;

    /* find_if */
    auto it = find_if(haystack.begin(), haystack.end(), check_even);
    if(it != haystack.end())
        cout << "Found an even number" << endl;
    else
        cout << "Did not find an even number" << endl;

    /* find_if_not */
    auto it2 = find_if(haystack.begin(), haystack.end(), check_even);
    if(it2 != haystack.end())
        cout << "Found an odd number" << endl;
    else
        cout << "Did not find an odd number" << endl;
    return 0;
}
