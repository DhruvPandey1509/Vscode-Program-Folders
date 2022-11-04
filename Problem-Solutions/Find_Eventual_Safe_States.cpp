#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool nocycle(vector<vector<int>> &g, int i, vector<int> &visited)
    {
        if (visited[i] != 0)
            return visited[i] == 1;

        visited[i] = 2;
        for (int adj : g[i])
        {
            if (!nocycle(g, adj, visited))
            {
                return false;
            }
        }
        visited[i] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();

        vector<int> visited(n, 0), ans;
        for (int i = 0; i < n; ++i)
        {
            if (nocycle(graph, i, visited))
            {
                ans.push_back(i);
            };
        }
        return ans;
    }
};