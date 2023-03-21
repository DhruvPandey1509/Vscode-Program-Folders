#include "bits/stdc++.h"
using namespace std;
#define ll long long
void solve()
{
    ll n, x;
    cin >> n >> x;
    ll left = 1, right = 1e9 + 5;
    ll count = 0;
    ll a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a + x < left || a - x > right)
        {
            count++;
            left = a - x;
            right = a + x;
        }
        else
        {
            left = max(left, a - x);
            right = min(right, a + x);
        }
    }
    cout << count << endl;
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