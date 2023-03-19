#include "bits/stdc++.h"
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    ll odd = 0, even = 0;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp % 2 == 0)
        {
            even += temp;
        }
        else
        {
            odd += temp;
        }
    }

    if (even > odd)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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