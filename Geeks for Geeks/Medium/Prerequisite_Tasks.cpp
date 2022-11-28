#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        vector<int> adj[N];

        // making adjacency list
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i].second;
            int v = prerequisites[i].first;

            adj[u].push_back(v);
        }

        // we are going to solve it using cycle detection technique(using topological sort)
        // if cycle present then it is not possible to finish all tasks
        vector<int> indegree(N, 0);

        for (int i = 0; i < N; i++)
        {
            for (auto nbr : adj[i])
            {
                indegree[nbr]++;
            }
        }
        int count = 0;
        queue<int> q;

        for (int i = 0; i < N; i++)
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
            count++;
            for (auto nbr : adj[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        return count == N;
    }
};
