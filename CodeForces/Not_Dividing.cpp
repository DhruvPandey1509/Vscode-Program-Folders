#include "bits/stdc++.h"
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    for (ll i = 0; i < n - 1; i++)
    {
        if (a[i] == 1)
            a[i]++;
        if (a[i + 1] % a[i] == 0)
        {
            a[i + 1]++;
        }
    }
    for (ll i = 0; i < n - 1; i++)

    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
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