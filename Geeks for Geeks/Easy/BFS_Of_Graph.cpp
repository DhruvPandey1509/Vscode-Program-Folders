#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> bfs;
        vector<bool> visited(V, false);

        queue<int> q;
        visited[0] = true;
        q.push(0);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            bfs.push_back(node);
            for (auto i : adj[node])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        return bfs;
    }
};