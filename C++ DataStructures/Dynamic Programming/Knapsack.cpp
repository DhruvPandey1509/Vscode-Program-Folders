#include <iostream>
#include <vector>
using namespace std;
// Recursive Approach 1
int knapsack(int *wts, int *prices, int n, int w)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }

    int inc = 0, exc = 0;

    if (wts[n - 1] <= w)
    {
        inc = prices[n - 1] + knapsack(wts, prices, n - 1, w - wts[n - 1]);
    }
    exc = knapsack(wts, prices, n - 1, w);
    return max(inc, exc);
}

// Recursive Approach 2
int knapsack2(int wts[], int prices[], int n, int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (wts[n - 1] >= W)
    {
        return knapsack2(wts, prices, n - 1, W);
    }

    return max(knapsack2(wts, prices, n - 1, W), prices[n - 1] + knapsack2(wts, prices, n - 1, W - wts[n - 1]));
}

// Approach 3 :- Bottom Up Solution
int knapsack3(int wts[], int prices[], int n, int W)
{
    vector<vector<int>> v(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                v[i][j] = 0;
            }

            else if (wts[i - 1] > j)
            {
                v[i][j] = v[i - 1][j];
            }

            else
            {
                v[i][j] = max(v[i - 1][j], prices[i - 1] + v[i - 1][j - wts[i - 1]]);
            }
        }
    }

    return v[n][W];
}

int main()
{
    int n = 4, w = 11;
    int wts[] = {2, 7, 3, 4};
    int prices[] = {2, 20, 20, 10};

    cout << knapsack(wts, prices, n, w) << endl;

    return 0;
}