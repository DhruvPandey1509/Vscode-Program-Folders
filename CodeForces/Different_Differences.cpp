#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, k;
    cin >> k >> n;
    int j = 1;
    int diff = 1;

    for (int i = 1; i <= k; i++)
    {
        cout << j << " ";
        if (n - (j + diff) >= k - (i + 1))//if taking the next element with diff as difference from prev element we can accommodate all the remaining elements.
        {
            j = j + diff;
            diff++;
        }
        else
        {
            j++;
        }
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