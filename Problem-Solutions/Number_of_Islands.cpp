#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    void mark(vector<vector<char>> &grid, int x, int y, int r, int c)
    {
        // if our index of row or col is out of bounds
        if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] != '1')
            return;

        grid[x][y] = '2';

        // checking for all the 4 directions to whether they are also land and to mark them all 2 so that             they are grouped together and counted as one whole island.
        mark(grid, x - 1, y, r, c);
        mark(grid, x, y - 1, r, c);
        mark(grid, x + 1, y, r, c);
        mark(grid, x, y + 1, r, c);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        if (rows == 0)
            return 0;
        int no_of_islands = 0;
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    mark(grid, i, j, rows, cols);
                    no_of_islands++;
                }
            }
        }

        return no_of_islands;
    }
};