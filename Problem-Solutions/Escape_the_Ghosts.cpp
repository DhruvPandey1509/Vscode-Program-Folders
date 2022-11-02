#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        int dis = abs(target[0]) + abs(target[1]);
        int n = ghosts.size();
        int ghostDis = 0;
        for (int i = 0; i < n; i++)
        {
            ghostDis = abs(target[0] - ghosts[i][0]) + abs(target[1] - ghosts[i][1]);
            if (ghostDis <= dis)
                return false;
        }

        return true;
    }
};