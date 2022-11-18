#include "bits/stdc++.h"
using namespace std;

//bfs traversal solution
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

//dfs traversal solution
class Solution {
  public:
  
    bool dfs(vector<int> adj[], vector<bool> vis, int node, int parent)
    {
        vis[node] = true;
        for(auto adjacent : adj[node])
        {
            if(!vis[adjacent])
            {
                if(dfs(adj, vis, adjacent, node)) return true;
            }
            else if(adjacent != parent) return true;
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> vis(V, false);
        
        for(int i = 0 ; i < V; i++)
        {
            if(!vis[i])
            {
                if(dfs(adj, vis, i, -1)) return true;
            }
        }
        return false;
    }
};