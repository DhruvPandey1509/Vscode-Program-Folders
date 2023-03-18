#include "bits/stdc++.h"
using namespace std;
#define ll long long

int solve()
{
    ll n, c;
    cin >> n >> c;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] = v[i] + i + 1;
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        c -= v[i];
        if (c < 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
int main()
{
    int testCase = 1;
    cin >> testCase;
    while (testCase--)
    {
        solve();
    }
    return 0;
}