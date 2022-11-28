#include "bits/stdc++.h"
#include "../../../debug.h"
using namespace std;

/*
 * By performing t2= std::move(t) thread t2 has the callable of thread t.
 * Assuming thread t2 already had a callable and is joinable the C++ runtime would call std::terminate.
 * This happens exactly in t2=std::move(t3) because t2 neither executed t2.join() nor t2.detach() before.
 */

int main()
{
    std::thread t([]{ cout << "lambda function"; }); std::thread t2;
    t2= std::move(t);
    std::thread t3([]{ cout << "lambda function"; });
    t2= std::move(t3); // std::terminate
}
