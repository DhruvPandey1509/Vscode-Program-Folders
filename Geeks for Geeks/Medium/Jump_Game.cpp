#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int canReach(int A[], int N)
    {
        vector<int> dp(N, 0);
        dp[0] = 1;

        for (int i = 0; i < N; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] && j + A[j] >= i)
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[N - 1];
    }
};