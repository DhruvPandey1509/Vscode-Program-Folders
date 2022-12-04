#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> addRow = {1, 0, -1, 0};
    vector<int> addCol = {0, 1, 0, -1};
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        if (source.first == destination.first && source.second == destination.second)
            return 0;
        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        distance[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        while (!q.empty())
        {
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int r = row + addRow[i];
                int c = col + addCol[i];

                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && dist + 1 < distance[r][c])
                {
                    distance[r][c] = dist + 1;
                    if (r == destination.first && c == destination.second)
                        return dist + 1;
                    q.push({1 + dist, {r, c}});
                }
            }
        }

        return -1;
    }
};
