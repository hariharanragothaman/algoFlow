class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& P, vector<int>& H, string D)
    {
        vector<int> ans{};
        set<int> removed;

        int n = static_cast<int>(P.size());
        map<int, vector<int>> hashmap;
        for(int i=0; i<P.size(); i++)
            hashmap[P[i]] = {P[i], H[i], int(D[i])};
        vector<vector<int>> St;

        for(auto c: hashmap)
        {
            vector<int> tmp = c.second;
            if(St.empty())
            {
                St.push_back(tmp);
            }
            else
            {
                // No Collision
                if( (St.back()[2] == 76 and tmp[2] == 82) || (St.back()[2] == tmp[2]))
                {
                    St.push_back(tmp);
                }
                else
                {
                    // As long as there is a collision keep doing this..
                    // Collision Scenario -- L: 76 & R: 82
                    // all of them are moving in same speed.
                    while(!St.empty() &&
                          (St.back()[2] == 82 and tmp[2] == 76) &&
                          removed.find(tmp[0]) == removed.end())
                    {
                        // cout << "Entering while loop " << endl;
                        if(tmp[1] == St.back()[1]) // same health
                        {
                            removed.insert(tmp[0]);
                            removed.insert(St.back()[0]);
                            St.pop_back();
                            break;
                        }
                        else if(tmp[1] > St.back()[1]) // different health
                        {
                            removed.insert(St.back()[0]);
                            St.pop_back();
                            tmp[1] -= 1;
                            hashmap[tmp[0]][1] = tmp[1];
                        }
                        else if(tmp[1] < St.back()[1])
                        {
                            St.back()[1] -= 1;
                            hashmap[St.back()[0]][1] = St.back()[1];
                            removed.insert(tmp[0]);
                        }

                    }
                    if(removed.find(tmp[0]) == removed.end())
                        St.push_back(tmp);
                }
            }
        }

        for(auto c: P)
            if(removed.find(c) == removed.end())
                ans.push_back(hashmap[c][1]);

        return ans;
    }
};
