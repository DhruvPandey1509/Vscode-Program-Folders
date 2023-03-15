#include "bits/stdc++.h"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n == 3)
    {
        cout << "NO" << endl;
        return;
    }
    int a = 1, b = -1;
    if (n % 2)
    {
        int m = n - 2;
        a = -(m / 2);
        b = (m + 1) / 2;
    }

    cout << "YES" << endl;
    int flag = true;
    for (int i = 0; i < n; i++)
    {
        if (flag)
            cout << a << " ";
        else
            cout << b << " ";
        flag = !flag;
    }
    cout << endl;
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