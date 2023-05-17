#include "bits/stdc++.h"
using namespace std;
#define ll long long
void solve()
{
    ll n, x, res = 0;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    sort(a.begin(), a.end());
    vector<ll> prefix(n, 0);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += a[i];
        prefix[i] += sum;
    }

    for (ll i = n - 1; i >= 0; i--)
    {
        ll diff = x - prefix[i];
        if (diff >= 0 and diff / (i + 1) >= 0)
        {
            res += (diff / (i + 1)) + 1;
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