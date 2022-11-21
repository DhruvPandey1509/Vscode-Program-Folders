#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int j = 0; j < m; j++)
        {
            // top row
            if (grid[0][j] == 1)
            {
                q.push({0, j});
            }

            // bottom row
            if (grid[n - 1][j] == 1)
            {
                q.push({n - 1, j});
            }
        }

        for (int i = 0; i < n; i++)
        {
            // leftmost column
            if (grid[i][0] == 1)
            {
                q.push({i, 0});
            }

            // rightmost column
            if (grid[i][m - 1] == 1)
            {
                q.push({i, m - 1});
            }
        }

        vector<int> addRow = {1, 0, -1, 0};
        vector<int> addCol = {0, 1, 0, -1};
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            vis[row][col] = 1;
            for (int i = 0; i < 4; i++)
            {
                int r = row + addRow[i];
                int c = col + addCol[i];

                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && vis[r][c] == 0)
                {
                    q.push({r, c});
                    vis[r][c] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 and vis[i][j] == 0)
                    count++;
            }
        }
        return count;
    }
};