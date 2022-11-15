#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int n;
    void dfs(vector<vector<int>> &isConnected, vector<bool> &vis, int node)
    {
        vis[node] = true;
        for (int i = 0; i < n; i++)
        {
            if (isConnected[node][i] == 1 and !vis[i])
            {
                dfs(isConnected, vis, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        n = isConnected.size();
        vector<bool> vis(n, false);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(isConnected, vis, i);
            }
        }

        return count;
    }
};
