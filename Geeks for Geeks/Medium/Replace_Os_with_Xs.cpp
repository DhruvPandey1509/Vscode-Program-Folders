#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> addRow = {1, 0, -1, 0};
    vector<int> addCol = {0, 1, 0, -1};
    void dfs(vector<vector<char>> mat, vector<vector<int>> &vis, int row, int col)
    {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < 4; i++)
        {
            int r = row + addRow[i];
            int c = col + addCol[i];

            if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && mat[r][c] == 'O')
            {
                dfs(mat, vis, r, c);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
        {
            // first row
            if (!vis[0][j] && mat[0][j] == 'O')
            {
                dfs(mat, vis, 0, j);
            }

            // last row
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
            {
                dfs(mat, vis, n - 1, j);
            }
        }

        for (int i = 0; i < n; i++)
        {
            // first column
            if (!vis[i][0] && mat[i][0] == 'O')
            {
                dfs(mat, vis, i, 0);
            }

            // last column
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
            {
                dfs(mat, vis, i, m - 1);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};