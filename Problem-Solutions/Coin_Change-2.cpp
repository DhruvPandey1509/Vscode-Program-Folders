#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> res(n + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            res[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                // j is depicting the column that we are taking as amount
                if (j < coins[i - 1]) // if(current amount is greater then the coin selected)
                {
                    res[i][j] = res[i - 1][j];
                }
                else
                {
                    res[i][j] = res[i][j - coins[i - 1]] + res[i - 1][j];
                }
            }
        }
        return res[n][amount];
    }
};