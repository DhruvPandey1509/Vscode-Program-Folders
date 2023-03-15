#include "bits/stdc++.h"
using namespace std;
#define ll long long
void solve()
{
    ll n;
    int k, extra = 0;
    cin >> n >> k;
    ll res = 0;
    vector<ll> l(26, 0);
    vector<ll> u(26, 0);
    char c;
    for (ll i = 0; i < n; i++)
    {
        cin >> c;
        if (c >= 'A' && c <= 'Z')
        {
            u[c - 'A']++;
        }
        else
        {
            l[c - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        int x = l[i];
        int y = u[i];
        int num = min(x, y);
        res += num;
        l[i] = abs(l[i] - u[i]);
        extra += (l[i] / 2);
    }
    res += min(k, extra);

    cout << res << endl;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}