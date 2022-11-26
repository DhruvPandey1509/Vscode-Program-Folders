#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int find(vector<vector<int>> &v, vector<int> &dp, vector<int> &startTime, int i, int n)
    {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int idx = lower_bound(startTime.begin(), startTime.end(), v[i][1]) - startTime.begin();
        int pick = v[i][2] + find(v, dp, startTime, idx, n);
        int notPick = find(v, dp, startTime, i + 1, n);
        return dp[i] = max(pick, notPick);
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> v;
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++)
        {
            v.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(v.begin(), v.end());
        sort(startTime.begin(), startTime.end());
        return find(v, dp, startTime, 0, n);
    }
};
