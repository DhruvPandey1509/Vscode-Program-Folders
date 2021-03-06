#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        bool flag = true;

        int r = grid.size();
        int c = grid.size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i == j || i == c - 1 - j)
                {
                    if (grid[i][j] == 0)
                        return false;
                }
                else if (grid[i][j] != 0)
                    return false;
            }
        }

        return true;
    }
};