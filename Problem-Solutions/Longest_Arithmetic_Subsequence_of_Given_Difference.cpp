#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        map<int, int> m;
        int n = arr.size();

        vector<int> dp(n, 0);

        dp[0] = 1;
        m[arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            if (m.find(arr[i] - difference) != m.end())
            {
                // current till index i we can make pervoius plus one
                dp[i] = m[arr[i] - difference] + 1;
                // than store in map for futher use;
                m[arr[i]] = dp[i];
            }
            else
            {
                m[arr[i]] = 1;
                dp[i] = 1;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
