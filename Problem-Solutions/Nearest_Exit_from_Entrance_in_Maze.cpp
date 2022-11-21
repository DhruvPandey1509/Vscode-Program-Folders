#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> addRow = {1, 0, -1, 0};
    vector<int> addCol = {0, 1, 0, -1};
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int steps = 0;
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = 1;

        while (!q.empty())
        {
            int size = q.size();
            for (int k = 0; k < size; k++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if ((row == 0 || row == n - 1 || col == 0 || col == m - 1) && (steps != 0))
                {
                    return steps;
                }

                for (int i = 0; i < 4; i++)
                {
                    int r = row + addRow[i];
                    int c = col + addCol[i];

                    if (r >= 0 && r < n && c >= 0 && c < m && vis[r][c] == 0 && maze[r][c] == '.')
                    {
                        vis[r][c] = 1;
                        q.push({r, c});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};