#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int r = 0, b = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
            r++;
        else if (s[i] == 'B')
            b++;
        else
        {
            if ((r > 0 and b > 0) || (r == 0 and b == 0))
            {
                r = 0;
                b = 0;
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    if (r > 0 and b > 0 || r == 0 and b == 0)
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