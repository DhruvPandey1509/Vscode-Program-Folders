#include "bits/stdc++.h"
using namespace std;

// T.C = O(V+E)
class Solution
{
    struct node
    {
        int destination; // destinatuon
        int wt;          // edje weight
    };
    struct qnode
    {
        int vertex;
        int dist; // source distance
    };

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        unordered_map<int, vector<node *>> adj;
        for (int i = 0; i < times.size(); i++)
        {
            node *newNode = new node;
            newNode->destination = times[i][1];
            newNode->wt = times[i][2];
            adj[times[i][0]].push_back(newNode);
        }

        qnode *qn = new qnode;
        qn->vertex = k;
        qn->dist = 0;
        queue<qnode *> q;
        q.push(qn);

        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        int time = 0;
        while (!q.empty())
        {
            qnode *curr = q.front();
            q.pop();

            for (auto i : adj[curr->vertex])
            {
                qnode *temp = new qnode;
                temp->vertex = i->destination;

                temp->dist = i->wt + curr->dist;
                if (distance[temp->vertex] > temp->dist)
                {
                    q.push(temp);
                    distance[temp->vertex] = i->wt + curr->dist;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (distance[i] == INT_MAX)
                return -1;
            time = max(time, distance[i]);
        }

        return time;
    }
};
