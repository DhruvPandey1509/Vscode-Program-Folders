#include <bits/stdc++.h>
using namespace std;

using namespace std;

int minCostKnapsack(int n, vector<int> &cost, int minWeight)
{
    vector<vector<int>> dp(n + 1, vector<int>(minWeight + 1, INT_MAX));

    // Initialize the base case
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 0; w <= minWeight; ++w)
        {
            dp[i][w] = dp[i - 1][w]; // Don't include the current item

            int weight = 1 << (i - 1);
            if (w >= weight)
            {
                dp[i][w] = min(dp[i][w], dp[i - 1][w - weight] + cost[i - 1]);
            }
        }
    }

    // Find the minimum cost to achieve at least minWeight
    int minCost = INT_MAX;
    for (int w = minWeight; w >= 0; --w)
    {
        if (dp[n][w] != INT_MAX)
        {
            minCost = dp[n][w];
            break;
        }
    }

    return minCost;
}

int main()
{
    int n = 5;
    vector<int> cost = {2, 5, 7, 11, 25};
    int minWeight = 26;

    int result = minCostKnapsack(n, cost, minWeight);
    cout << "Minimum cost needed: " << result << endl;
    cout << "Hello" << endl;

    return 0;
}

vector<string> getRequestStatus(vector<string> requests)
{
    map<string, vector<int>> mp;
    int n = requests.size();
    int k = 0;
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        bool canProcess = false;
        auto v = mp[requests[i]];
        auto it1 = lower_bound(v.begin(), v.end(), k - 4);
        auto it2 = lower_bound(v.begin(), v.end(), k - 29);
        if (v.end() - it1 < 2 && v.end() - it2 < 5)
        {
            canProcess = true;
        }

        if (canProcess)
        {
            mp[requests[i]].push_back(k);
            ans.push_back("{status: 200, message: OK}");
        }
        else
        {
            ans.push_back("{status: 429, message: Too many requests}");
                   
        }
                k++;
           
    }
        return ans;
}