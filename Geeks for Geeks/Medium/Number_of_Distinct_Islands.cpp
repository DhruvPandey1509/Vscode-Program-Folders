#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int n, m;
    vector<int> addRow = {-1, 0, 1, 0};
    vector<int> addCol = {0, -1, 0, 1};

    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &v, int row, int col, int base_row, int base_col)
    {
        vis[row][col] = 1;
        v.push_back({row - base_row, col - base_col});

        for (int i = 0; i < 4; i++)
        {
            int r = row + addRow[i];
            int c = col + addCol[i];

            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && vis[r][c] == 0)
            {
                dfs(grid, vis, v, r, c, base_row, base_col);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        set<vector<pair<int, int>>> s;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                {
                    vector<pair<int, int>> v;
                    dfs(grid, vis, v, i, j, i, j);
                    s.insert(v);
                }
            }
        }

        return s.size();
    }
};