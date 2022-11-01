#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rc, int cc)
    {
        vector<vector<int>> res;
        queue<pair<int, int>> q;
        q.push({rc, cc});

        bool visited[100][100]{false};

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            int i = p.first;
            int j = p.second;
            q.pop();

            if (visited[i][j])
                continue;
            visited[i][j] = true;

            res.push_back({i, j});
            if (i + 1 < rows)
            {
                q.push({i + 1, j});
            }
            if (i - 1 >= 0)
            {
                q.push({i - 1, j});
            }
            if (j + 1 < cols)
            {
                q.push({i, j + 1});
            }
            if (j - 1 >= 0)
            {
                q.push({i, j - 1});
            }
        }
        return res;
    }
};
