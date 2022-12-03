#include "bits/stdc++.h"
using namespace std;

void dfsHelper(vector<int> *adj, bool *vis, int node)
{
    vis[node] = true;

    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfsHelper(adj, vis, i);
        }
        return;
    }
}

void dfs(vector<int> *adj, int v, int node)
{
    bool vis[v];
    dfsHelper(adj, vis, node);
}

int main()
{
    int v, E, s, d;
    cout << "Enter Number of vertices : ";
    cin >> v;
    cout << "Enter Number of Edges : ";
    cin >> E;
    vector<int> adj[v];

    for (int i = 0; i < E; i++)
    {
        cin >> s >> d;
        adj[s].push_back(d);
    }
    int node;
    cout << "Enter Node to start traversing from";
    cin >> node;
    dfs(adj, v, node);

    return 0;
}