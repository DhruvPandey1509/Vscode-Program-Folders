#include "bits/stdc++.h"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    int val, res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        m[val]++;
    }

    for (auto it : m)
    {
        int num = it.first;
        int freq = it.second;
        if (num == 1)
        {
            if (freq % 2 == 0)
            {
                int pairs = freq / 2;
                res += pairs;
            }
            else
            {
                int pairs = freq / 2;
                int rem = freq % 2;
                res += pairs + rem;
            }
        }
        else
        {
            res += freq;
        }
    }
    cout << res << endl;
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