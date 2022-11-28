#include"bits/stdc++.h"
using namespace std;

//using dfs
class Solution {
  public:
    bool dfs(vector<int> adj[], vector<int> &vis, vector<int> &pathVis, int node)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto nbr : adj[node])
        {
            if(!vis[nbr])
            {
                if(dfs(adj, vis, pathVis, nbr)) return true;
            }
            else if(pathVis[nbr]) return true;
        }
        
        pathVis[node] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        
        for(int i =0 ; i < V; i++)
        {
            if(!vis[i])
            {
                if(dfs(adj, vis, pathVis, i)) return true;
            }
        }
        
        return false;
    }
};

//Using Topological sort
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        int count = 0;
        for(int i = 0; i < V; i++)
        {
            for(auto nbr : adj[i])
            {
                indegree[nbr]++;
            }
        }
        
        queue<int> q;
        for(int i =0; i < V; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(auto nbr : adj[node])
            {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
        
        if(count == V) return false;
        
        return true;
    }
};