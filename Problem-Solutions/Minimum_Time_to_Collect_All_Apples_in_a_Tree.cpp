#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> adj;
    vector<bool> apple;
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        adj.resize(n);
        apple = hasApple;
        for (int i = 0; i < edges.size(); ++i)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int l = 0;
        solve(0, -1, l);
        return l;
    }

    bool solve(int s, int p, int &len)
    {

        bool isAnyChild = false;
        for (auto i : adj[s])
        { // visit all child i.e. simple dfs on tree
            if (i != p)
            {
                if (solve(i, s, len))
                { // if child child subtree have apple
                    isAnyChild = true;
                    len += 2; // one for going to child one for coming back to parent
                }
            }
        }

        return apple[s] || isAnyChild;
    }
};

// Minimum Time to Collect All Apples in a Tree