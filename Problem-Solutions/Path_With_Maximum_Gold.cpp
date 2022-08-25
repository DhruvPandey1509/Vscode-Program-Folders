#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int rows, cols, maxGold = 0;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void traverse(vector<vector<int>> &grid, int r, int c, int goldCollected)
    {
        // base case if current row or col is out of grid bound or the cell contains 0 gold
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)
        {
            return;
        }

        int currentCoin = grid[r][c];
        grid[r][c] = 0; // so that we do not visit the same path
        maxGold = max(maxGold, goldCollected + currentCoin);

        // now traversing in 4 possible direction :- left, right, up, down of the cell
        for (int i = 0; i < directions.size(); i++)
        {
            traverse(grid, r + directions[i][0], c + directions[i][1], currentCoin + goldCollected);
        }

        grid[r][c] = currentCoin; // restoring the goldCoin in the current cell so that it can be traversed by some other combination
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        rows = grid.size();
        cols = grid[0].size();

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] != 0)
                {
                    traverse(grid, r, c, 0);
                }
            }
        }

        return maxGold;
    }
};