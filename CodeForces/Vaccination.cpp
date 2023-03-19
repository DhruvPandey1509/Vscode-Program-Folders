#include "bits/stdc++.h"
using namespace std;
#define ll long long
void solve()
{
    ll n, k, d, w, res = 1;
    cin >> n >> k >> d >> w;
    vector<ll> t(n);
    for (auto &i : t)
    {
        cin >> i;
    }
    for (int i = 0, p = 0; i < n; i++)
    {
        cout << (t[i] - t[p] - w) << " " << d << endl;
        cout << i - p + 1 << " " << k << endl;
        if ((t[i] - t[p] - w > d) || (i - p + 1 > k))
        {
            p = i;
            res++;
        }
    }
    cout << res << endl;
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