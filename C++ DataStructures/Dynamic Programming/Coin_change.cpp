#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Bottom Up Approach
int minNumberOfCoinForChange(vector<int> denoms, int m)
{
    vector<int> dp(m + 1, 0);
    dp[0] = 0;
 
    for (int i = 1; i <= m; i++)
    {
        dp[i] = INT_MAX;

        for (auto c : denoms)
        {
            if (i - c >= 0 && dp[i - c] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    return dp[m] == INT_MAX ? -1 : dp[m];
}

int main()
{
    vector<int> denoms = {1, 5, 7, 10}; // types
    int m = 8;
        cin>>m;
        cout<<m;
    cout << minNumberOfCoinForChange(denoms, m) << endl;

    cout << minNumberOfCoinForChange(denoms, m) << endl;
    cout << minNumberOfCoinForChange(denoms, 15) << endl;
    cout << minNumberOfCoinForChange({1, 3, 7, 10}, 15) << endl;

    return 0;
}