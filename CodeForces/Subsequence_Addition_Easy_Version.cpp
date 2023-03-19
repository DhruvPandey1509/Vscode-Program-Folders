#include "bits/stdc++.h"
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin >> n;
    vector<ll> c(n);
    for (auto &i : c)
    {
        cin >> i;
    }
    sort(c.begin(), c.end());
    ll sum = 1;
    if (c[0] != 1)
    {
        cout << "NO" << endl;
        return;
    }
    for (ll i = 1; i < n; i++)
    {
        if (c[i] <= sum)
        {
            sum += c[i];
            continue;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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