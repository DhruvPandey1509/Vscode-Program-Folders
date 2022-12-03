#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];

        for (auto i : prerequisites)
        {
            adj[i[0]].push_back(i[1]);
        }

        vector<int> indegree(numCourses);
        for (int i = 0; i < numCourses; i++)
        {
            for (auto nbr : adj[i])
            {
                indegree[nbr]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> v;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            v.push_back(node);
            for (auto nbr : adj[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        if (v.size() != numCourses)
            return {};

        reverse(v.begin(), v.end());
        return v;
    }
};