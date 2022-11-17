#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool detectCycle(vector<int> adj[], vector<bool> vis, int src)
    {
        vis[src] = true;
        queue<pair<int, int>> q;
        q.push({src, -1}); // first = curr node    second = parent node

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node])
            {
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = true;
                    q.push({adjacentNode, node});
                }
                else if (parent != adjacentNode)
                    return true;
            }
        }
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {

        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detectCycle(adj, vis, i))
                    return true;
            }
        }
        return false;
    }
};
