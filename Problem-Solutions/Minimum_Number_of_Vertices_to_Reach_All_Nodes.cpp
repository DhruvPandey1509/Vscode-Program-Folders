#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> inorder(n, 0), res;
        for (int i = 0; i < n; i++)
        {
            for (auto nbr : adj[i])
            {
                inorder[nbr]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (inorder[i] == 0)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};


