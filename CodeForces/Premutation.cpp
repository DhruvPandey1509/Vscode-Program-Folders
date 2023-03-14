#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n;
    ll num;
    cin >> n;
    vector<ll> res(n + 1);

    vector<ll> pos[n + 1];

    ll m = n;

    while (m--)
    {
        for (ll i = 1; i <= n - 1; i++)
        {
            cin >> num;

            pos[num].push_back(i);
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        sort(pos[i].begin(), pos[i].end());
    }

    for (ll i = 1; i <= n; i++)
    {
        if (pos[i][n - 2] == n - 1)
        {
            if (pos[i][0] == n - 1)
            {
                res[n] = i;
            }
            else
            {
                res[n - 1] = i;
            }
        }
        else
        {
            res[pos[i][n - 2]] = i;
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    cout << "\n";
}
int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}