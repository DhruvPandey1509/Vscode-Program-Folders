#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n, i, j, ans;
    string a, b;
    cin >> n >> b;
    ans = 0;
    cin >> a;

    ll suff[n];

    if (a[n - 1] == 'g')
    {
        suff[n - 1] = n - 1;
    }
    else
    {
        suff[n - 1] = -1;
    }

    for (i = n - 2; i >= 0; i--)
    {
        if (a[i] == 'g')
        {
            suff[i] = i;
        }
        else
        {
            suff[i] = suff[i + 1];
        }
    }

    for (i = 0; i < n; i++)
    {
        if (a[i] == b[0])
        {
            if (suff[i] == -1)
            {
                ans = max(ans, n - 1 - i + 1 + suff[0]);
            }
            else
            {
                ans = max(ans, suff[i] - i);
            }
        }
    }

    cout << ans << "\n";
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}