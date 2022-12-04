#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        vector<vector<int>> row, col;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            int ones = 0, zeros = 0;
            for (int j = 0; j < m; j++)
            {
                ones += grid[i][j] == 1;
                zeros += grid[i][j] == 0;
            }
            row.push_back({zeros, ones});
        }
        for (int j = 0; j < grid[0].size(); j++)
        {
            int ones = 0, zeros = 0;
            for (int i = 0; i < n; i++)
            {
                ones += grid[i][j] == 1;
                zeros += grid[i][j] == 0;
            }
            col.push_back({zeros, ones});
        }

        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            int ones = 0, zeros = 0;
            for (int j = 0; j < m; j++)
            {
                res[i][j] = row[i][1] + col[j][1] - row[i][0] - col[j][0];
            }
        }
        return res;
    }
};
