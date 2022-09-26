#include "bits/stdc++.h"
using namespace std;
//Recursion
class Solution
{
public:
    int solve(vector<vector<int>> &v, int i, int j1, int j2, int r, int c)
    {
        if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
            return -1e7;
        if (i == r - 1)
        {
            if (j1 == j2)
            {
                return v[i][j1];
            }
            else
            {
                return v[i][j1] + v[i][j2];
            }
        }

        int res = 0;
        for (int dj1 = -1; dj1 < 2; dj1++)
        {
            for (int dj2 = -1; dj2 < 2; dj2++)
            {
                if (j1 == j2)
                    res = max(res, v[i][j1] + solve(v, i + 1, j1 + dj1, j2 + dj2, r, c));
                else
                    res = max(res, v[i][j1] + v[i][j2] + solve(v, i + 1, j1 + dj1, j2 + dj2, r, c));
            }
        }

        return res;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        return solve(grid, 0, 0, c - 1, r, c);
    }
};
// Top down (recursion + Memoization)
class Solution
{
public:
    int solve(vector<vector<int>> &v, vector<vector<vector<int>>> &dp, int i, int j1, int j2, int r, int c)
    {
        if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
            return -1e7;
        if (i == r - 1)
        {
            if (j1 == j2)
            {
                return v[i][j1];
            }
            else
            {
                return v[i][j1] + v[i][j2];
            }
        }
        if (dp[i][j1][j2] != INT_MIN)
            return dp[i][j1][j2];

        int res = 0;
        for (int dj1 = -1; dj1 < 2; dj1++)
        {
            for (int dj2 = -1; dj2 < 2; dj2++)
            {
                if (j1 == j2)
                    res = max(res, v[i][j1] + solve(v, dp, i + 1, j1 + dj1, j2 + dj2, r, c));
                else
                    res = max(res, v[i][j1] + v[i][j2] + solve(v, dp, i + 1, j1 + dj1, j2 + dj2, r, c));
            }
        }

        return dp[i][j1][j2] = res;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, INT_MIN)));
        return solve(grid, dp, 0, 0, c - 1, r, c);
    }
};
// Bottom Up Approach (Tabulation)
class Solution
{
public:
   int cherryPickup(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                if (j1 == j2)
                    dp[r - 1][j1][j2] = grid[r-1][j1];
                else
                    dp[r - 1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }

        for(int i = r-2; i >= 0; i--)
        {
            for(int j1 = 0; j1 < c; j1++)
            {
                for(int j2 = 0; j2 < c; j2++)
                {
                    int res = INT_MIN;
                    for(int dj1 = -1; dj1 < 2; dj1++)
                    {
                        for(int dj2 = -1; dj2 < 2; dj2++)
                        {
                            int val;
                            if(j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];
                            
                            if(j1+dj1 >= 0 and j1+dj1 < c and j2+dj2 >=0 and j2+dj2 < c)
                            {
                                val += dp[i+1][j1+dj1][j2+dj2];
                            }
                            else
                            {
                                val += -1e8;
                            }
                            
                            res = max(res, val);
                        }
                    }
                    
                    dp[i][j1][j2] = res;
                }
            }
        }

       return dp[0][0][c-1];
    }
};
// (Tabulation + Space Optimizaion)
class Solution
{
public:
   int cherryPickup(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> prev(c, vector<int> (c, 0));
        vector<vector<int>> curr(c, vector<int> (c, 0));
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                if (j1 == j2)
                    prev[j1][j2] = grid[r-1][j1];
                else
                    prev[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }

        for(int i = r-2; i >= 0; i--)
        {
            for(int j1 = 0; j1 < c; j1++)
            {
                for(int j2 = 0; j2 < c; j2++)
                {
                    int res = INT_MIN;
                    for(int dj1 = -1; dj1 < 2; dj1++)
                    {
                        for(int dj2 = -1; dj2 < 2; dj2++)
                        {
                            int val;
                            if(j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];
                            
                            if(j1+dj1 >= 0 and j1+dj1 < c and j2+dj2 >=0 and j2+dj2 < c)
                            {
                                val += prev[j1+dj1][j2+dj2];
                            }
                            else
                            {
                                val += -1e8;
                            }
                            
                            res = max(res, val);
                        }
                    }
                    
                    curr[j1][j2] = res;
                }
            }
            
            prev = curr;
        }

       return prev[0][c-1];
    }
};