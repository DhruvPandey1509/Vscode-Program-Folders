#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vp;

class Graph
{
    int V;
    vp *adj;
    vector<bool> isVisited;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new vp[V];
        isVisited.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void dfs(int u);
};

void Graph ::dfs(int u)
{
    isVisited[u] = true;
    vector<int> adjlist = adj[u];
    cout << u << " ";
    for (auto i : adjlist)
    {
        if (isVisited[i] != true)
        {
            dfs(i);
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.dfs(0);

    return 0;
}