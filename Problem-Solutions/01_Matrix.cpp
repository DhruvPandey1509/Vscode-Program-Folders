#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        vector<int> addRow = {1, 0, -1, 0};
        vector<int> addCol = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int d = q.front().second;
            q.pop();
            dis[row][col] = d;

            for (int i = 0; i < 4; i++)
            {
                int r = row + addRow[i];
                int c = col + addCol[i];

                if (r >= 0 && r < n && c >= 0 && c < m && vis[r][c] == 0)
                {
                    vis[r][c] = 1;
                    q.push({{r, c}, d + 1});
                }
            }
        }

        return dis;
    }
};