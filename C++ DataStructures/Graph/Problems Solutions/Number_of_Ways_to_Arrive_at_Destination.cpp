#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n];

        for (auto i : roads)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // distance of this node to its parent node, node

        vector<int> distance(n, 1e9), ways(n, 0);
        distance[0] = 0;
        ways[0] = 1;

        int mod = 1e9 + 7;
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto i : adj[node])
            {
                int adjacent = i.first;     // nbr of the node
                int edge_weight = i.second; // edge weight from node to adjacent(nbr node)
                if (dis + edge_weight < distance[adjacent])
                {
                    distance[adjacent] = dis + edge_weight;
                    pq.push({distance[adjacent], adjacent});
                    ways[adjacent] = ways[node];
                }
                else if (dis + edge_weight == distance[adjacent])
                {
                    ways[adjacent] = (ways[adjacent] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
