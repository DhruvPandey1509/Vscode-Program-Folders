#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int getMaximumConsecutive(vector<int> &coins)
    {
        int res = 0;
        int n = coins.size();
        sort(coins.begin(), coins.end());
        for (int i = 0; i < n; i++)
        {
            if (coins[i] <= res + 1)
            {
                res += coins[i];
            }
            else
                break;
        }
        return res + 1;
    }
};
