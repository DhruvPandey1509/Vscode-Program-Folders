#include "bits/stdc++.h"
using namespace std;

typedef vector<pair<int, pair<int, int>>> viii;

class Graph
{
    int V;
    vector<list<pair<int, int>>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    // void bfs(int s);
    viii prims();
};

// void Graph ::bfs(int s)
// {
//     vector<bool> isVisited(V, false);

//     isVisited[s] = true;

//     list<int> q;
//     q.push_back(s);

//     while (!q.empty())
//     {
//         s = q.front();
//         cout << s << " ";
//         q.pop_front();

//         for (auto adjacent : adj[s])
//         {
//             if (!isVisited[adjacent.second])
//             {
//                 isVisited[adjacent.second] = true;
//                 q.push_back(adjacent.second);
//             }
//         }
//     }
//     cout << endl;
// }

viii Graph ::prims()
{
    vector<bool> isVisited(V, false);
    vector<int> parent(V, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int s = 0;
    viii res;

    vector<int> key(V, INT_MAX);
    pq.push({0, s});

    key[s] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (isVisited[u] == true)
            continue;

        isVisited[u] = true;

        for (auto i : adj[u])
        {
            int v = i.second;
            int w = i.first;

            if (isVisited[v] == false and key[v] > w)
            {
                key[v] = w;
                pq.push({w, v});
                parent[v] = u;
            }
        }
    }

    vector<pair<int, int>> weight;

    for (int i = 0; i < V; i++)
    {
        weight.push_back({i, key[i]});
    }

    for (int i = 1; i < V; i++)
    {
        res.push_back({weight[i].second, {parent[i], i}});
    }

    return res;
}

int main()
{
    int V;
    cin >> V;

    Graph g(V);
    g.addEdge(0, 1, 6);
    g.addEdge(0, 5, 4);
    g.addEdge(1, 5, 5);
    g.addEdge(5, 4, 2);
    g.addEdge(1, 2, 7);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 4, 9);
    g.addEdge(2, 3, 8);
    g.addEdge(4, 3, 3);

    viii res = g.prims();
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].first << " " << res[i].second.first << " " << res[i].second.second << endl;
    }

    return 0;
}