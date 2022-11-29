#include "../debug.h"
using namespace std;

struct Player
{
    string name;
    int score;
};

bool comp(Player p1, Player p2)
{
    if(p1.score>p2.score) return true;
    if(p1.score==p2.score) return p1.name<p2.name;
    return false;
}
vector<Player> comparator(vector<Player> players)
{
    sort(players.begin(),players.end(), comp);
    return players;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    Player p;
    vector<Player> players;
    vector<Player> op;

    while(n--)
    {
        cin >> p.name >> p.score;
        players.push_back(p);
    }

    op = comparator(players);
    for(auto c: op)
    {
        cout << c.name << " " << c.score << endl;
    }
}
