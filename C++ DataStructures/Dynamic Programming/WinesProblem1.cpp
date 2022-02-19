#include <iostream>
using namespace std;

// Bottom Up method

int main()
{
    int a[] = {2, 3, 5, 1, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int dp[10][10] = {0};

    cout << wines(dp, a, 0, n - 1, 1) << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}