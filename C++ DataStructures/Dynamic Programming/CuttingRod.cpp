/*
Rod cutting Problem
-----------------------
N = 8

Example-1

length   | 1  2  3  4  5   6   7   8
--------------------------------------
price    | 1  5  8  9  10  17  17  20

Max Profit = 22


Example-2

length   | 1  2  3  4  5   6   7   8
--------------------------------------
price    | 3  5  8  9  10  17  17  20
.                              len         price
Max Profit = 24        as     1*8 = 8  :  3*8 = 24

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive Solution
int maxProfit(int prices[], int n)
{
    // base case
    if (n <= 0)
    {
        return 0;
    }

    // rec case
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int cut_len = i + 1;

        int curr_ans = prices[i] + maxProfit(prices, n - cut_len);

        ans = max(ans, curr_ans);
    }

    return ans;
}

// Bottom Up Solution
int maxProfitDP(int prices[], int n)
{
    vector<int> dp(n + 1);
    dp[0] = 0;

    for (int len = 1; len <= n; len++)
    {
        int ans = INT_MIN;
        for (int i = 0; i < len; i++)
        {
            int cut_len = i + 1;
            int curr_ans = prices[i] + dp[len - cut_len];
            ans = max(curr_ans, ans);
        }
        dp[len] = ans;
    } 
    // computed the answer for dp[len];

    return dp[n];
}

int main()
{
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices) / sizeof(prices[0]);

    int prices1[] = {3, 5, 8, 9, 10, 17, 17, 20};
    int n1 = sizeof(prices1) / sizeof(prices1[0]);

    cout << maxProfit(prices, n) << endl;
    cout << maxProfitDP(prices1, n1) << endl;

    return 0;
}