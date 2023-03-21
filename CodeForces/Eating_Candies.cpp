#include "bits/stdc++.h"
using namespace std;

// prefix, suffix sum
void solve1()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    vector<int> pre(n), suf(n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            pre[i] = v[i];
            suf[n - 1] = v[n - 1];
        }
        else
        {
            pre[i] = pre[i - 1] + v[i];
            suf[n - 1 - i] = suf[n - i] + v[n - i - 1];
        }
    }
    int l = 0, r = n - 1;
    int count = 0;
    while (l < r)
    {
        if (pre[l] == suf[r])
        {
            count = l + 1 + n - r + 1 - 1;
        }
        if (pre[l] < suf[r])
            l++;
        else
            r--;
    }

    cout << count << endl;
    return;
}
// space optimized
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    int leftSum = 0, rightSum = 0;
    int l = 0, r = n - 1;
    int count = 0;
    leftSum = v[l];
    rightSum = v[r];
    while (l < r)
    {
        if (leftSum == rightSum)
        {
            count = l + 1 + n - r + 1 - 1;
        }
        if (leftSum < rightSum)
        {
            l++;
            leftSum += v[l];
        }
        else
        {
            r--;
            rightSum += v[r];
        }
    }

    cout << count << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
