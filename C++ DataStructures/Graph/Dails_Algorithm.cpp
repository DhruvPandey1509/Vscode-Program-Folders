#include "bits/stdc++.h"
using namespace std;

int bfs01(vector<pair<int, int>> adj[], int n)
{
    vector<int> distance(n + 1, INT_MAX);
    distance[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int src = q.front();
        q.pop();

        for (auto nbr : adj[src])
        {
            int dest = nbr.first;
            int wt = nbr.second;
            if (distance[dest] > distance[src] + wt)
            {
                distance[dest] = distance[src] + wt;
                q.push(dest);
            }
        }
    }

    return distance[n] == INT_MAX ? -1 : distance[n];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];
    int src, dest;
    for (int i = 0; i < m; i++)
    {
        cin >> src >> dest;
        adj[src].push_back({dest, 0});
        adj[dest].push_back({src, 1});
    }

    cout << bfs01(adj, n) << endl;
}
