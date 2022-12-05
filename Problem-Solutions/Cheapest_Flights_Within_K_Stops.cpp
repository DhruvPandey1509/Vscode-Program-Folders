#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        for (auto i : flights)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> distance(n, 1e9);
        distance[src] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // stops, node, cost

        while (!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            for (auto i : adj[node])
            {
                int adjacent = i.first;
                int edgeWeight = i.second;
                if (cost + edgeWeight < distance[adjacent] && stops <= k)
                {
                    distance[adjacent] = cost + edgeWeight;
                    q.push({stops + 1, {adjacent, distance[adjacent]}});
                }
            }
        }

        if (distance[dst] == 1e9)
            return -1;
        return distance[dst];
    }
};
