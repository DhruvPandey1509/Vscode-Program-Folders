#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols));
        bool flag = false;
        for (int i = 0; i < rows; i++)
        {
            if (flag || obstacleGrid[i][0] == 1)
            {
                flag = true;
                dp[i][0] = 0;
            }
            else
            {
                dp[i][0] = 1;
            }
        }
        flag = false;
        for (int j = 0; j < cols; j++)
        {
            if (flag || obstacleGrid[0][j] == 1)
            {
                flag = true;
                dp[0][j] = 0;
            }
            else
            {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }
};