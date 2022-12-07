#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n == 1)
            return 0;
        if (n == 2)
        {
            return abs(points[0][0] - points[1][0]) + abs(points[0][1] - points[1][1]);
        }

        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        vector<int> dist(n, INT_MAX), vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        int sum = 0;

        while (!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if (vis[node])
                continue;

            sum += wt;
            vis[node] = true;

            for (auto i : adj[node])
            {
                int adjnode = i.first;
                int edw = i.second;

                if (!vis[adjnode] && dist[adjnode] > edw)
                {
                    dist[adjnode] = edw;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }

        return sum;
    }
};
