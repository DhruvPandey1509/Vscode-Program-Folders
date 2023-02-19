#include "bits/stdc++.h"
using namespace std;

struct node
{
    int destination;
    int weight;
};

void Bfs01(vector<pair<int, int>> adj[], int src, int V)
{
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    deque<int> q;
    q.push_front(src);
    while (!q.empty())
    {
        int dest = q.front();
        q.pop_front();
        for (int i = 0; i < adj[dest].size(); i++)
        {
            if (dist[adj[dest][i].first] > dist[dest] + adj[dest][i].second)
            {
                dist[adj[dest][i].first] = dist[dest] + adj[dest][i].second;

                if (adj[dest][i].second == 0)
                {
                    q.push_front(adj[dest][i].first);
                }
                else
                    q.push_back(adj[dest][i].first);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << " ";
    }
}

void bfs_01(vector<node> edg[], int V)
{
    // vector<int> distance(V, INT_MAX);
    // distance[0] = 0;
    // deque<int> q;
    // q.push_front(0);

    // while (!q.empty())
    // {
    //     int src = q.front();
    //     q.pop_front();
    //     for (int i = 0; i < edg[src].size(); i++)
    //     {
    //         if (distance[edg[src][i].destination] > distance[src] + edg[src][i].weight)
    //         {
    //             distance[edg[src][i].destination] = distance[src] + edg[src][i].weight;

    //             if (edg[src][i].weight == 0)
    //             {
    //                 q.push_front(edg[src][i].destination);
    //             }
    //             else
    //                 q.push_back(edg[src][i].destination);
    //         }
    //     }
    // }
    // for (int i = 0; i < V; i++)
    // {
    //     cout << distance[i] << " ";
    // }

    vector<int> distance(V, INT_MAX);
    distance[0] = 0; // distance of src from itself is 0;
    deque<int> q;
    q.push_front(0);

    while (!q.empty())
    {
        int src = q.front();
        q.pop_front();

        for (auto i : edg[src])
        {
            if (distance[i.destination] > distance[src] + i.weight)
            {
                distance[i.destination] = distance[src] + i.weight;

                if (i.weight == 0)
                    q.push_front(i.destination);
                else
                    q.push_back(i.destination);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << distance[i] << " ";
    }
}

int main()
{
    int V;
    cout << "Enter Number of Nodes : ";
    cin >> V;
    vector<node> edg[V];
    // vector<pair<int, int>> adj[V];
    cout << "Enter src, destination, and wt" << endl;
    int src, dest, wt = 0;
    // while (1)
    // {
    //     cin >> src >> dest >> wt;
    //     if (wt == -1)
    //         break;
    //     adj[src].push_back({dest, wt});
    // }

    while (1)
    {
        cin >> src >> dest >> wt;
        if (wt == -1)
            break;
        edg[src].push_back({dest, wt});
        edg[dest].push_back({src, wt});
    }
    bfs_01(edg, V);
    // Bfs01(adj, 0, V);
    return 0;
}