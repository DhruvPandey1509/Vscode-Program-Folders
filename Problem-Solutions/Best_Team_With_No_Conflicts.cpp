#include"bits/stdc++.h"
using namespace std;

//Sorting for score in increasing order
//Applying longest increasing subsequence method for age corresponding to the sorted score with little modification

//Memoization
class Solution {
public:
    int helper(vector<pair<int, int>> &v,vector<vector<int>> &dp, int idx, int prev_idx, int n)
    {
        if(idx == n) return 0;
        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];
        int res = 0 + helper(v,dp, idx+1, prev_idx, n);
        if(prev_idx == -1 || v[idx].second >= v[prev_idx].second)
        {
            res = max(res, v[idx].first + helper(v,dp, idx+1, idx, n));
        }
        return dp[idx][prev_idx+1] = res;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> v;
        int n = scores.size();
        for(int i = 0 ; i < n; i++)
        {
            v.push_back({scores[i], ages[i]});
        }

        sort(v.begin(), v.end());
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return helper(v,dp, 0, -1, n);
    }
};


class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        if(n == 1) return scores[0];

        vector<pair<int, int>> v;
        for(int i = 0 ; i < n; i++)
        {
            v.push_back({scores[i], ages[i]});
        }
        sort(v.begin(), v.end());

        vector<int> dp(n+1);

        for(int i = 0 ; i < n; i++)
        {
            dp[i] = v[i].first;
        }
        int res = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0 ; j < i; j++)
            {
                if(v[i].second >= v[j].second)
                {
                    dp[i] = max(dp[i], v[i].first + dp[j]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};