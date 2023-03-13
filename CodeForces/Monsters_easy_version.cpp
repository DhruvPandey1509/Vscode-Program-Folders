#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    sort(v.begin(), v.end());
    long long count = 0, curr_min = 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= curr_min)
        {
            count += v[i] - curr_min;
            curr_min++;
        }
    }
    cout << count << endl;
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