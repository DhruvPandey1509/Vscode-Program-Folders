#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll, bool> vis;
bool recurr(ll n, ll &m)
{
    if (n == m)
    {
        return true;
    }
    else
    {
        if (n > m and n % 3 == 0)
        {
            if (!vis.count(n / 3))
                vis[n / 3] = recurr(n / 3, m);
            if (!vis.count((n / 3) * 2))
                vis[(n / 3) * 2] = recurr((n / 3) * 2, m);
            return vis[n / 3] || vis[(n / 3) * 2];
        }
        return false;
    }
}
int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vis.clear();
        bool res = recurr(n, m);
        if (res)
            cout << "YES";
        else
        {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}