#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0, 0}); // wt, node
        while (!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if (vis[node])
                continue;
            vis[node] = 1;
            sum += wt;

            for (auto i : adj[node])
            {
                int adjnode = i[0];
                int edw = i[1];

                if (!vis[adjnode])
                {
                    pq.push({edw, adjnode});
                }
            }
        }

        return sum;
    }
};
