#include "bits/stdc++.h"
using namespace std;
#define ll long long
void solve()
{
    int n, m;
    cin >> n >> m;
    ll sum = 0;
    int temp;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        pq.push(temp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        pq.pop();
        pq.push(temp);
    }

    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;
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