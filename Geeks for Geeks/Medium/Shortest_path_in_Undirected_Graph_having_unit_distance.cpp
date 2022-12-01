#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> adj[N];

        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        queue<int> q;
        vector<int> dist(N, 1e9);
        dist[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto nbr : adj[node])
            {
                if (dist[node] + 1 < dist[nbr])
                {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }

        vector<int> res(N, -1);
        for (int i = 0; i < N; i++)
        {
            if (dist[i] != 1e9)
            {
                res[i] = dist[i];
            }
        }

        return res;
    }
};
