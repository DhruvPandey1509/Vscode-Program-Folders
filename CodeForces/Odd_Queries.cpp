#include "bits/stdc++.h"
using namespace std;
#define ll long long

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n), pre(n, 0);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    pre[0] = v[0];
    for (ll i = 1; i < n; i++)
    {
        pre[i] = v[i] + pre[i - 1];
    }

    while (q--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        ll kss = pre[r - 1] - (pre[l - 1] - v[l - 1]);
        ll nsm = sum - kss + (r - l + 1) * k;
        if (nsm % 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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