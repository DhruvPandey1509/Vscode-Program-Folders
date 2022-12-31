#include "bits/stdc++.h"
using namespace std;
class Solution
{
    int m, n;

    vector<int> addRow = {-1, 1, 0, 0};
    vector<int> addCol = {0, 0, -1, 1};

public:
    int dfs(int i, int j, int left, pair<int, int> dest, vector<vector<int>> &grid)
    {
        // base case

        if (left == -1 and pair<int, int>(i, j) == dest)
            return 1;

        grid[i][j] = -1;

        int ans = 0;
        for (int k = 0; k < 4; k++)
        {
            int r = i + addRow[k];
            int c = j + addCol[k];

            if (r >= 0 and c >= 0 and r < m and c < n and grid[r][c] != -1)
                ans += dfs(r, c, left - 1, dest, grid);
        }

        // Backtrack
        grid[i][j] = 0;

        return ans;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();

        pair<int, int> src, dest;
        int empty = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    empty++;
                if (grid[i][j] == 1)
                    src = {i, j};
                if (grid[i][j] == 2)
                    dest = {i, j};
            }
        }

        return dfs(src.first, src.second, empty, dest, grid);
    }
};