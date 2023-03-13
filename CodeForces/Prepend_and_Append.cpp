#include "bits/stdc++.h"
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if (s[0] == s[n - 1])
    {
        cout << n << endl;
        return;
    }

    int st = 0, en = n - 1;
    while (st < en)
    {
        if (s[st] != s[en])
        {
            st++;
            en--;
        }
        else
            break;
    }
    if (st > en)
        cout << 0 << endl;
    else
        cout << en - st + 1 << endl;
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