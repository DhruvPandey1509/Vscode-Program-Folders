#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> iPair;

class Graph
{
    int V;
    vector<pair<int, int>> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new vector<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w);
    void primMST();
};
void Graph ::addEdge(int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
void Graph ::primMST()
{
    // Create a priority queue to store vertices that
    // are being primMST.
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    int src = 0;

    // Create a vector for keys and initialize all
    // keys as infinite (INF)
    vector<int> key(V, INT_MAX);

    // To store parent array which in turn store MST
    vector<int> parent(V, -1);

    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);

    // Insert source itself in priority queue and initialize
    // its key as 0.
    pq.push({0, src});
    key[src] = 0;

    while (!pq.empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair
        int u = pq.top().second;
        pq.pop();

        if (inMST[u] == true)
        {
            continue;
        }

        inMST[u] = true;

        vector<pair<int, int>>::iterator i;

        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    vector<pair<int, iPair>> res;

    for (int i = 0; i < V; i++)
    {
        res.push_back({i, {parent[i], key[i]}});
    }

    cout << "Source"<<"   "<<" Destination "<< "   "<< " Weight " << endl;
    for (int i = 1; i < V; i++)
    {
        cout << res[i].first << "             " << res[i].second.first << "             " << res[i].second.second << endl;
    }

    // for (int i = 0; i < V; i++)
    // {
    //     cout << parent[i] << " : " << i << endl;
    // }
}

int main()
{
    int V = 6;
    Graph g(V);
    g.addEdge(0, 1, 6);
    g.addEdge(0, 5, 4);
    g.addEdge(1, 5, 5);
    g.addEdge(1, 4, 1);
    g.addEdge(1, 2, 7);
    g.addEdge(2, 4, 9);
    g.addEdge(2, 3, 8);
    g.addEdge(4, 3, 3);
    g.addEdge(4, 5, 2);

    g.primMST();

    return 0;
}