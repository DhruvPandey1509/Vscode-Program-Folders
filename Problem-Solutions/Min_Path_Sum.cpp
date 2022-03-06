#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {

        int n = grid.size();    // number of rows
        int m = grid[0].size(); // number of columns

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i > 0 && j > 0)
                {
                    grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]); // since we can move either right col or down row
                }
                else if (i > 0) // when j = 0 then we cant get j-1 index since it is out of bounds
                {
                    grid[i][j] = grid[i][j] + grid[i - 1][j];
                }
                else if (j > 0) // when i = 0 then we cant get j-1 index since it is out of bounds
                {
                    grid[i][j] = grid[i][j] + grid[i][j - 1];
                }
            }
        }

        return grid[n - 1][m - 1];
    }
};