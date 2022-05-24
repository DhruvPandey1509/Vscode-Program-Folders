#include "bits/stdc++.h"
using namespace std;

class Graph
{
    int V;
    vector<list<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v);
    void bfs(int s);            // bfs traversal
    int minEdges(int s, int d); // minimum moves (edges) to reach from source to destination node
};

void Graph ::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph ::bfs(int s) // bfs traversal
{
    vector<bool> isVisited(V, false);

    list<int> q;

    isVisited[s] = true;
    q.push_back(s);

    while (!q.empty())
    {
        s = q.front();
        cout << s << " ";
        q.pop_front();

        for (auto adjacent : adj[s])
        {
            if (!isVisited[adjacent])
            {
                isVisited[adjacent] = true;
                q.push_back(adjacent);
            }
        }
    }

    cout << endl;
}
int Graph ::minEdges(int s, int d) // minimum moves (edges) to reach from source to destination node
{
    vector<bool> isVisited(V, false);

    list<pair<int, int>> q;
    isVisited[s] = true;

    q.push_back({s, 0});
    int count = 0;
    while (!q.empty())
    {
        s = q.front().first;
        count = q.front().second;
        if (s == d)
        {
            return count;
        }
        // cout << s << " ";
        q.pop_front();

        for (auto adjacent : adj[s])
        {
            if (!isVisited[adjacent])
            {
                isVisited[adjacent] = true;
                q.push_back({adjacent, count + 1});
            }
        }
    }
}
int main()
{
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(3, 6);
    g.addEdge(6, 4);
    g.addEdge(4, 7);
    g.addEdge(4, 1);
    g.addEdge(1, 5);
    g.addEdge(3, 5);
    g.addEdge(2, 5);
    g.addEdge(5, 7);

    g.bfs(2);

    cout << g.minEdges(2, 7) << endl;

    return 0;
}