#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n, known_count, unknown_count, i, res;
    cin >> n;
    ll b[n];
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    known_count = unknown_count = 0;
    res = 0;
    for (i = 0; i < n; i++)
    {
        if (b[i] == 2)
        {
            known_count = known_count + unknown_count;
            if (known_count > 0)
                res = max(res, (known_count + 2) / 2);
            unknown_count = 0;
        }
        else
        {
            unknown_count++;
            if (known_count == 0)
                res = max(res, unknown_count);
            else
                res = max(res, ((known_count + 2) / 2 )+ unknown_count);
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