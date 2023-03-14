#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<bool> v(n, false);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (ll i = 0; i < n; i++)
    {
        if (i >= a[i])
        {
            v[i] = true;
        }
    }

    ll count = 0;

    for (ll i = 0; i < n; i++)
    {
        if (v[i] == true)
        {
            if (i == 0)
            {
                count++;
            }
            else if (v[i - 1] == false)
            {
                count++;
            }
        }
    }

    if (a[0] > 0)
    {
        count++;
    }
    cout << count << endl;
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