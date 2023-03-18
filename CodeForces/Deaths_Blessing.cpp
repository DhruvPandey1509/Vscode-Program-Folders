#include "bits/stdc++.h"
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    for (auto &i : b)
    {
        cin >> i;
    }

    ll sum = 0;
    ll max_b = INT_MIN;
    for (ll i = 0; i < n ; i++)
    {
        sum += a[i] + b[i];
        max_b = max(max_b, b[i]);
    }
    sum -= max_b;
    cout << sum << endl;
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