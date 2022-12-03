#include "bits/stdc++.h"
using namespace std;

void bfs(vector<int> *adj, int v, int node)
{
    queue<int> q;
    q.push(node);
    bool vis[v] = {false};

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        cout << f << endl;
        for (auto nbrs : adj[f])
        {
            if (!vis[nbrs])
            {
                q.push(nbrs);
                vis[nbrs] = true;
            }
        }
    }
    return;
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
    bfs(adj, v, node);

    return 0;
}