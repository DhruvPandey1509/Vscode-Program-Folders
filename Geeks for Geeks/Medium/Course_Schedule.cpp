#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
    {
        vector<int> adj[n];
        vector<int> res;
        // making adjacency list
        for (int i = 0; i < m; i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        // we are going to solve it using cycle detection technique(using topological sort)
        // if cycle present then it is not possible to finish all tasks
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto nbr : adj[i])
            {
                indegree[nbr]++;
            }
        }
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto nbr : adj[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        if (res.size() == n)
            return res;

        return {};
    }
};