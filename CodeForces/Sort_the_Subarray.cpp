#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    for (auto &i : b)
    {
        cin >> i;
    }
    int l = 0, r = n - 1;
    while (a[l] == b[l])
        l++;
    while (a[r] == b[r])
        r--;

    while (l > 0 and b[l] >= b[l - 1])
        l--;
    while (r < n - 1 && b[r] <= b[r + 1])
        r++;

    cout << l + 1 << " " << r + 1 << endl;
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