#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll x;
void bs(ll l, ll h, vector<ll> &a, ll i)
{
    if (l <= h)
    {
        ll m = (l + h) / 2;

        if (a[m] >= (i - m + 1))
        {
            if (m == l)
            {
                x = m;
                return;
            }
            else
            {
                if (a[m - 1] >= (i - (m - 1) + 1))
                {
                    bs(l, m - 1, a, i);
                }
                else
                {
                    x = m;
                    return;
                }
            }
        }
        else
        {
            bs(m + 1, h, a, i);
        }
    }
    return;
}
void solve()
{
    ll n, i, j;
    cin >> n;

    vector<ll> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }

    cout << 1 << " ";
    for (i = 1; i < n; i++)
    {
        bs(0, i, a, i);
        cout << i - x + 1 << " ";
    }
    cout << endl;
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