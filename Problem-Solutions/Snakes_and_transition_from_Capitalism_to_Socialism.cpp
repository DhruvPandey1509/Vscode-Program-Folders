#include "bits/stdc++.h"
using namespace std;
bool isValid(int r, int c, int n, int m)
{
    return r >= 0 && c >= 0 && r < n && c < m;
}
int multiSourceBfs(vector<vector<int>> &grid, int max_val, int n, int m)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int hours = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == max_val)
            {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 and j == 0)
                    continue;

                int r = row + i;
                int c = col + j;
                if (isValid(r, c, n, m) && !vis[r][c])
                {
                    q.push({r, c});
                    vis[r][c] = vis[row][col] + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            hours = max(hours, vis[i][j]);
        }
    }

    return hours - 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));
        int max_val = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                max_val = max(max_val, grid[i][j]);
            }
        }

        cout << multiSourceBfs(grid, max_val, n, m) << endl;
    }
    return 0;
}
