#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxArea = 0;
    int dfs(vector<vector<int>> &grid, int r, int c, int rows, int cols)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1)
            return 0;

        grid[r][c] = 2;

        return 1 + (dfs(grid, r - 1, c, rows, cols) +
                    dfs(grid, r, c - 1, rows, cols) +
                    dfs(grid, r + 1, c, rows, cols) +
                    dfs(grid, r, c + 1, rows, cols));
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        if (rows == 0)
            return 0;

        int cols = grid[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    maxArea = max(dfs(grid, i, j, rows, cols), maxArea);
                }
            }
        }
        return maxArea;
    }
};