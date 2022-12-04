#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    vector<int> addRow = {1, 0, -1, 0};
    vector<int> addCol = {0, 1, 0, -1};
    int minimumEffortPath(vector<vector<int>> &heights)
    {

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        distance[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == n - 1 && col == m - 1)
                return diff;
            for (int i = 0; i < 4; i++)
            {
                int r = row + addRow[i];
                int c = col + addCol[i];

                if (r >= 0 && r < n && c >= 0 && c < m)
                {
                    int newEffort = max(abs(heights[row][col] - heights[r][c]), diff);
                    if (newEffort < distance[r][c])
                    {
                        distance[r][c] = newEffort;
                        pq.push({newEffort, {r, c}});
                    }
                }
            }
        }
        return 0;
    }
};
