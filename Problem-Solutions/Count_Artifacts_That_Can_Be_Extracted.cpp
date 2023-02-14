#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig)
    {
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for (int i = 0; i < dig.size(); i++)
        {
            int x = dig[i][0], y = dig[i][1];
            vis[x][y] = true;
        }

        int count = 0;
        for (int x = 0; x < artifacts.size(); x++)
        {
            bool flag = true;
            for (int i = artifacts[x][0]; i <= artifacts[x][2]; i++)
            {
                for (int j = artifacts[x][1]; j <= artifacts[x][3]; j++)
                {
                    if (!vis[i][j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
            }
            if (flag)
                count++;
        }

        return count;
    }
};
