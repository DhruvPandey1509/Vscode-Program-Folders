#include "bits/stdc++.h"
using namespace std;

bool helper(string s, string str)
{
    s += str;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        string str;
        bool flag = true;

        for (int i = 0; i < n - 1; i++)
        {
            if (s1[i] == s1[i + 1])
            {
                str = s1.substr(i + 1, n);
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            reverse(str.begin(), str.end());
            if (helper(s2, str))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;

            continue;
        }

        for (int i = 0; i < m - 1; i++)
        {
            if (s2[i] == s2[i + 1])
            {
                str = s2.substr(i + 1, m);
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            reverse(str.begin(), str.end());
            if (helper(s1, str))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }

    return 0;
}