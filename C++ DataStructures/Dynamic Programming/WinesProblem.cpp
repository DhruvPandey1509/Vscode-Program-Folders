#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// top down approach since it is recursive

int wines(int price[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        // bottom row to top row
        for (int j = 0; j < n; j++)
        {
            if(i == j)
            {
                dp[i][j] = n*price[i];
            }
            else if (i <= j)
            {
                // dp(i...j)
                int y = n - (j - i);
                int pick_left = price[i] * y + dp[i + 1][j];
                int pick_right = price[j] * y + dp[i][j - 1];

                dp[i][j] = max(pick_left, pick_right);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[0][n - 1];
}

int main()
{
    int a[] = {2, 3, 5, 1, 4};
    int n = sizeof(a) / sizeof(a[0]);
    cout << wines(a, n) << endl;

    return 0;
} 