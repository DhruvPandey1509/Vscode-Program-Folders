#include "bits/stdc++.h"
using namespace std;
#define ll long long

void solve()
{
    ll n, k, h1, h_idx, p1;
    cin >> n >> k;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> h, p; // first = value, second = index
    vector<bool> vis(n);
    ll sum = 0;
    ll val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        h.push({val, i});
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        p.push({val, i});
    }
    ll n1 = 0; // dead monster count;
    while (k > 0 and n1 < n)
    {
        sum += k;
        while (!h.empty())
        {
            h1 = h.top().first;
            h_idx = h.top().second;
            h1 -= sum;

            if (h1 <= 0)
            {
                vis[h_idx] = true;
                h.pop();
                n1++;
            }
            else
                break;
        }
        while (!p.empty() and vis[p.top().second] == true)
        {
            p.pop();
        }
        if (!p.empty())
        {
            p1 = p.top().first;
            k -= p1;
        }
    }

    n1 == n ? cout << "YES" << endl : cout << "NO" << endl;
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