#include "bits/stdc++.h"
using namespace std;
int solve(vector<int> &v, int i, int k)
{
    if (i == 0)
    {
        return 0;
    }
    int res = INT_MAX;
    int jump = 0;
    for (int j = 1; j <= k; j++)
    {
        if (j - i >= 0)
            break;
        jump = solve(v, i - j, k) + abs(v[i] - v[i - j]);
        res = min(res, jump);
    }
    return res;
}
int main()
{
    vector<int> v = {10, 200, 100, 10};
    int n = v.size();
    vector<int> dp(n, -1);
    int k = 0;
    cout << solve(v, n - 1, k);
    return 0;
}