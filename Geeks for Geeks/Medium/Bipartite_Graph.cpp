#include "bits/stdc++.h"
using namespace std;
// BFS
class Solution
{
public:
    bool check(vector<int> adj[], vector<int> &color, int start, int v)
    {
        queue<int> q;
        q.push(start);
        color[start] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto nbr : adj[node])
            {
                if (color[nbr] == -1)
                {
                    q.push(nbr);
                    color[nbr] = !color[node];
                }
                else if (color[nbr] == color[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!check(adj, color, i, V))
                    return false;
            }
        }
        return true;
    }
};

// DFS
class Solution
{
public:
    bool dfs(vector<int> adj[], vector<int> &color, int node, int col)
    {
        color[node] = col;
        for (auto nbr : adj[node])
        {
            if (color[nbr] == -1)
            {
                if (!dfs(adj, color, nbr, !col))
                    return false;
            }
            else if (color[nbr] == color[node])
                return false;
        }

        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs(adj, color, i, 0))
                    return false;
            }
        }
        return true;
    }
};