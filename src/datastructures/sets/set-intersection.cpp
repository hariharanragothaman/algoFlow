#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<int> S1, S2;
    S1 = {1, 3, 5, 7, 9};
    S2 = {2, 3, 4, 7, 10};
    set<int> intersect;
    set_intersection(S1.begin(), S1.end(), S2.begin(), S2.end(), inserter(intersect, intersect.begin()));

}
