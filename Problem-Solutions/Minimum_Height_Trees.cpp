#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0), res;

        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
                q.push(i);
        }

        while (!q.empty())
        {
            int size = q.size();
            res.clear();
            for (int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();
                res.push_back(curr);
                for (auto i : adj[curr])
                {
                    indegree[i]--;
                    if (indegree[i] == 1)
                        q.push(i);
                }
            }
        }

        if (n == 1)
            res.push_back(0);

        return res;
    }
};