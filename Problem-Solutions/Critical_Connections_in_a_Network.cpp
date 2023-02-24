#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int timer = 1;
    void dfs(vector<int> adj[], vector<int> &vis, vector<int> &time, vector<int> &low, int curr_node, int parent, vector<vector<int>> &bridges)
    {
        vis[curr_node] = 1;
        time[curr_node] = timer++;
        low[curr_node] = time[curr_node];

        for (auto nbr : adj[curr_node])
        {
            if (nbr == parent)
                continue;
            if (!vis[nbr])
            {
                dfs(adj, vis, time, low, nbr, curr_node, bridges);
                low[curr_node] = min(low[curr_node], low[nbr]);

                if (low[nbr] > time[curr_node])
                {
                    bridges.push_back({curr_node, nbr});
                }
            }
            else
            {
                low[curr_node] = min(low[curr_node], low[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> bridges;
        vector<int> adj[n];
        for (auto i : connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n, 0);
        vector<int> time(n, 0), low(n, 0);
        dfs(adj, vis, time, low, 0, -1, bridges);
        return bridges;
    }
};
