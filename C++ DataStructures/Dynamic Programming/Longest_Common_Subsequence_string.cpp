 #include <iostream>
#include <cstring>
#include <climits>
#include <math.h>
using namespace std;

int lis(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    int dp[n1 + 1][n2 + 1];
    memset(dp, 0, (n1 + 1) * (n2 + 1) * sizeof(int));

    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    return dp[0][0];
}

int main()
{
    string s1 = "abcdef";
    string s2 = "ace";
    cout << lis(s2, s2) << endl;
}
