#include "bits/stdc++.h"
using namespace std;
bool solve(vector<int> &v)
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto c : s)
    {
        if (v[0] == 1 && v[1] == 1)
            return true;
        if (c == 'L')
            v[0]--;
        else if (c == 'R')
            v[0]++;
        else if (c == 'U')
            v[1]++;
        else if (c == 'D')
            v[1]--;
    }
    if (v[0] == 1 && v[1] == 1)
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v = {0, 0};
        if (solve(v))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}