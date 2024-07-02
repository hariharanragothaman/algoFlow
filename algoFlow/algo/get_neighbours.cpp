#include "../../debug.h"
using namespace std;


vector<vector<int>> get_neighbours(int& r, int& c, int& R, int& C)
{
    vector<vector<int>> directions = {{r+1, c}, {r, c+1}, {r-1, c}, {r, c-1}};
    vector<vector<int>> nei;
    for(auto c: directions)
    {
        if(0<= c[0] && c[0]< R && c[1] >= 0 && c[1] < C)
            nei.push_back({c[0], c[1]});
    }
    return nei;
}

int main()
{
  return 0; 
}
