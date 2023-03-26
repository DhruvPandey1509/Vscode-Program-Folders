#include "bits/stdc++.h"
using namespace std;
void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, char> converse;
    converse['R'] = 'B';
    converse['B'] = 'R';

    string res = "";
    char first = 'z';

    for (int i = 0; i < n; i++)
    {
        while (i < n && s[i] == '?')
            i++;

        if (i == n)
            break;

        if ((i - res.size()) % 2)
        {
            char cons = s[i];
            for (int j = res.size(); j <= i; j++)
            {
                res += converse[cons];
                cons = converse[cons];
            }
        }
        else
        {
            char cons = converse[s[i]];
            for (int j = res.size(); j <= i; j++)
            {
                res += converse[cons];
                cons = converse[cons];
            }
        }
    }

    if (res.size() == 0)
    {
        char m = 'B';
        for (int i = 0; i < n; i++)
        {
            res += m;
            m = converse[m];
        }
    }

    while (res.size() < n)
    {
        int last = res.size();
        res += converse[res[last - 1]];
    }

    cout << res << endl;
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