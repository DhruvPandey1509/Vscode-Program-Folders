#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
    {
        vector<vector<int>> res;
        vector<vector<int>> seen(8, vector<int>(8, 0));

        for (int i = 0; i < queens.size(); i++)
        {
            seen[queens[i][0]][queens[i][1]] = 1;
        }

        vector<int> directions = {-1, 0, 1};

        // covering all possible directions
        for (auto dx : directions)
        {
            for (auto dy : directions)
            {
                if (dx == 0 and dy == 0)
                    continue;

                int x = king[0];
                int y = king[1];

                while (x + dx >= 0 and x + dx < 8 and y + dy >= 0 and y + dy < 8)
                {
                    x += dx;
                    y += dy;

                    // breaking helps to ensure that it will not search in the same direction
                    if (seen[x][y])
                    {
                        res.push_back({x, y});
                        break;
                    }
                }
            }
        }

        return res;
    }
};