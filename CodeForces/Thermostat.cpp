#include "bits/stdc++.h"
using namespace std;
#define ll long long
// 1759C
ll helper(ll a, ll b, ll l, ll r, ll x)
{
    if(b-a >= x) return 1;
    else if(a-l >= x || r - b >= x) return 2;
    else if(r-a >= x && b - l >= x) return 3;
    else return -1;
}

void solve()
{
    ll l, r, x, a, b;
    cin >> l >> r >> x;
    cin >> a >> b;
    if(a == b) cout<<0<<endl;
    else if(a < b)
    {
        cout<<helper(a, b, l, r, x)<<endl;
    }
    else
    {
        cout<<helper(b, a, l, r, x)<<endl;
    }

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