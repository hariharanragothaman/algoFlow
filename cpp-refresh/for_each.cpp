#include <iostream>
#include <ranges>
#include <vector>
using namespace std; 

int main()
{
  vector<int> A{1, 2, 3};
  auto print = [](const int& c) {cout << c << " "; };
  auto increment = [](int& d) { d++; };
  for_each(A.begin(), A.end(),  increment);
  for_each(A.begin(), A.end(), print);
  ranges::for_each(A, increment);
  return 0; 
}
