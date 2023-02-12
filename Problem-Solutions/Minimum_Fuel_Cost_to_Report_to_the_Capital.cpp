#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    long long res;
    long long dfs(vector<vector<int>> &adj, int node, vector<int> &vis, int seats)
    {
        vis[node] = true;

        long long count = 1;
        for (int i = 0; i < adj[node].size(); i++)
        {
            int curr_node = adj[node][i];
            if (!vis[curr_node])
            {
                count += dfs(adj, curr_node, vis, seats);
            }
        }

        long long x = count / seats;
        if (count % seats)
            x++;
        if (node != 0)
            res += x;
        return count;
    }
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        if (roads.size() == 0)
            return 0;
        int n = roads.size();
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n; i++)
        {
            int u = roads[i][0], v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        res = 0;
        vector<int> vis(n + 1, 0);
        dfs(adj, 0, vis, seats);

        return res;
    }
};