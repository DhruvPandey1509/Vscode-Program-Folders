#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n + 1];
        for (auto i : edges)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        vector<int> distance(n + 1, 1e9), parent(n + 1);
        distance[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for (auto i : adj[node])
            {
                int nbr = i.first;
                int weight = i.second;
                if (dis + weight < distance[nbr])
                {
                    distance[nbr] = dis + weight;
                    pq.push({distance[nbr], nbr});
                    parent[nbr] = node;
                }
            }
        }

        if (distance[n] == 1e9)
            return {-1};

        vector<int> path;
        int node = n;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};
