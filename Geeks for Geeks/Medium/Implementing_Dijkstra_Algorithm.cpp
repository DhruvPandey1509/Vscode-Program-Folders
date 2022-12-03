#include "bits/stdc++.h"
using namespace std;

// Priority Queue(Min Heap) Implementation
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(V, 1e9);
        distance[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;

            pq.pop();
            for (auto i : adj[node])
            {
                int w = i[1];
                int nbr = i[0];

                if (dis + w < distance[nbr])
                {
                    distance[nbr] = dis + w;
                    pq.push({distance[nbr], nbr});
                }
            }
        }
        return distance;
    }
};

// Set Implementation
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> s;
        vector<int> distance(V, 1e9);
        distance[S] = 0;
        s.insert({0, S});

        while (!s.empty())
        {
            auto i = *(s.begin());
            int node = i.second;
            int dis = i.first;
            s.erase(i);

            for (auto it : adj[node])
            {
                int nbr = it[0];
                int w = it[1];

                if (dis + w < distance[nbr])
                {
                    if (distance[nbr] != 1e9)
                    {
                        s.erase({distance[nbr], nbr});
                    }
                    distance[nbr] = dis + w;
                    s.insert({distance[nbr], nbr});
                }
            }
        }

        return distance;
    }
};
