#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    /*  Function to implement Dijkstra
     *   adj: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> adj, int S)
    {
        vector<int> dis(V, 1e8);

        dis[S] = 0;

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj)
            {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                cout << dis[u] << " ";
                cout << dis[v] << " ";
                if (dis[v] > (dis[u] + w))
                {
                    dis[v] = dis[u] + w;
                }
            }
        }

        return dis;
    }
};