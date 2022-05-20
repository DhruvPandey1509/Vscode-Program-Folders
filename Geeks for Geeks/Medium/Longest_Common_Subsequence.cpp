#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int lcs(int x, int y, string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        // Top Down Approach
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n1][n2];

        // int n1 = s1.size();
        // int n2 = s2.size();
        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        // for(int i = n1-1 ; i >=0; i--)
        // {
        //     for(int j = n2-1; j >=0; j--)
        //     {
        //         if(s1[i] == s2[j])
        //         {
        //             dp[i][j] = 1 + dp[i+1][j+1];
        //         }
        //         else
        //         {
        //             dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
        //         }
        //     }
        // }
        // return dp[0][0];
    }
};

//Another way of top down approach

int funct(string s1, string s2)
{
    int dp[s1.size()+1][s2.size()+1];
        memset(dp,0,(s2.size()+1)*(s1.size()+1)*sizeof(int));
        
        for(int i = s1.length()-1 ; i >=0; i--)
        {
            for(int j = s2.length()-1; j >=0; j--)
            {
                if(s1[i] == s2[j])
                {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
}