#include "bits/stdc++.h"
using namespace std;
#define ll long long
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int bs(vector<int> &a)
{
    
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    // Alice
    sort(a.begin(), a.end());
    bool flag = true; // true for alice
    for (int i = 1; i < n; i++)
    {
        int x = bs(a);
        a[x]--;
        swap(a[0], a[x]);
        if (a[0] == 0)
        {
            if (flag)
                cout << "Alice" << endl;
            else
                cout << "Bob" << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
    }
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