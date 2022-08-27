#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        set<pair<int, int>> set;

        for (auto obstacle : obstacles)
        {
            set.insert({obstacle[0], obstacle[1]});
        }
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0, x = 0, y = 0, res = 0;
        for (auto cmd : commands)
        {
            if (cmd < 0)
            {
                if (cmd == -1)
                {
                    d++;
                }
                else if (cmd == -2)
                {
                    d--;
                    d += 4;
                }
                d %= 4;
            }
            else
            {
                for (int i = 0; i < cmd; ++i)
                {
                    x += dir[d][0];
                    y += dir[d][1];
                    if (set.count({x, y}))
                    {
                        x -= dir[d][0];
                        y -= dir[d][1];
                        break;
                    }
                    res = max(x * x + y * y, res);
                }
            }
        }
        return res;
    }
};