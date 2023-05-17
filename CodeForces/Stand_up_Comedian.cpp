#include "bits/stdc++.h"
using namespace std;
#define ll long long
void solve()
{
    ll a1, a2, a3, a4, i, j, res;
    cin >> a1 >> a2 >> a3 >> a4;
    if (a1 == 0)
    {
        if (a2 > 0 || a3 > 0 || a4 > 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        return;
    }

    res = a1;
    if (a2 > a3)
    {
        swap(a2, a3);
    }

    res = res + 2 * a2;
    a3 -= a2;
    res = res + min(a1 + 1, a3 + a4);
    cout << res << endl;
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