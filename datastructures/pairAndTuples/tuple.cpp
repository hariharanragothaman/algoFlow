#include "bits/stdc++.h"
#include "../../debug.h"
using namespace std;
using std::get;

/*
 * You can create tuples of arbitrary length and types with std::tuple.
 * The class template needs the header <tuple>. std::tuple is a generalization of std::pair.
 * You can convert between tuples with two elements and pairs.
 * The tuple has, like his younger brother std::pair, a default, a copy, and a move constructor.
 * You can swap tuples with the function std::swap.
 * The i-th element of a tuple t can be referenced by the function template std::get: std::get<i-1>(t).
 * By std::get<type>(t) you can directly refer to the element of the type type.
 * Tuples support the comparison operators ==, !=, <, >, <= and >=.
 * If you compare two tuples, the elements of the tuples will be compared lexicographically. The comparison starts at index 0.
 *
 */


int main()
{
    std::tuple<std::string, int, float> tup1("first", 3, 4.17f);
    auto tup2= std::make_tuple("second", 4, 1.1);

    std::cout << get<0>(tup1) << ", " << get<1>(tup1) << ", "
              << get<2>(tup1) << std::endl; // first, 3, 4.17

    std::cout << get<0>(tup2) << ", " << get<1>(tup2) << ", "
              << get<2>(tup2) << std::endl; // second, 4, 1.1

    std::cout << (tup1 < tup2) << std::endl; // true

    get<0>(tup2)= "Second";

    std::cout << get<0>(tup2) << "," << get<1>(tup2) << ","
              << get<2>(tup2) << std::endl;  // Second, 4, 1.1

    std::cout << (tup1 < tup2) << std::endl; // false

    auto pair= std::make_pair(1, true);
    std::tuple<int, bool> tup= pair;

    return 0;
}
