#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<ll> s(n);
    priority_queue<ll> pq;
    ll res = 0;
    for (auto &i : s)
    {
        cin >> i;
    }

    for (ll i = 0; i < n; i++)
    {
        if (s[i] != 0)
        {
            pq.push(s[i]);
        }
        else
        {
            if (!pq.empty())
            {
                res += pq.top();
                pq.pop();
            }
        }
    }

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
}