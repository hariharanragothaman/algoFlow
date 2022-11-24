#include "bits/stdc++.h"
#include "../debug.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#include <functional> // for less


typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> new_data_set;
int main()
{
    new_data_set p;
    p.insert(5);
    p.insert(2);
    p.insert(6);
    p.insert(4);
    for(auto c: p)
        cout << c;
    cout << endl;
    cout << "The value at 3rd index :: " << *p.find_by_order(3) << endl;
    cout << "The index of number 6:: " << p.order_of_key(6) << endl;
    cout << "The index of number seven :: " << p.order_of_key(7) << endl;
    return 0;
}
