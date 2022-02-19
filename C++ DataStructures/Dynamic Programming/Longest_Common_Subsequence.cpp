#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int lis(vector<int> v)
{
    int n = v.size();
    vector<int> dp(n, 1);

    int len = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
                len = max(dp[i], len);
            }
        }
    }

    return len;
}

int main()
{
    vector<int> v = {50, 4, 10, 8, 30, 100};
    cout << lis(v) << endl; 
    return 0;
}