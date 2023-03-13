#include "bits/stdc++.h"
using namespace std;
map<char, int> m;
void solve()
{
    char c;
    cin >> c;
    if (m.find(c) != m.end())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    m.insert({'c', 1});
    m.insert({'o', 1});
    m.insert({'d', 1});
    m.insert({'e', 1});
    m.insert({'f', 1});
    m.insert({'r', 1});
    m.insert({'f', 1});
    m.insert({'s', 1});
    while (t--)
    {
        solve();
    }

    return 0;
}