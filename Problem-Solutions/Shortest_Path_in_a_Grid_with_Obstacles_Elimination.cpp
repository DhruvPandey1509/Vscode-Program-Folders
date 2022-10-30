#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        // This vector stores the number of obstacles that we can still remove after walking through that cell
        vector<vector<int>> visited(m, vector<int>(n, -1));

        queue<vector<int>> q;
        // x, y, currentLength, remaining k
        q.push({0, 0, 0, k});
        while (!q.empty())
        {

            vector<int> v = q.front();
            q.pop();

            int x = v[0], y = v[1];

            // Invalid cases being dealt here since it's easier to write one condition instead of 4 while pushing.
            if (x < 0 || x >= m || y < 0 || y >= n)
                continue;

            // If you've reached the end, great, return the currentLength!
            if (x == m - 1 && y == n - 1)
                return v[2]; // currentLength of the path

            // If we hit an obstacle & we don't have any Ks remaining, continue
            // If we still have Ks to spend, we spend 1.
            if (grid[x][y] == 1)
            {
                if (v[3] > 0)
                    v[3]--;
                else
                    continue;
            }

            // If this cell is already visited with a K value lesser than this one, we would want to save Ks for future use, so we continue
            // This is the most important condition and part of the solution!
            if (visited[x][y] != -1 && visited[x][y] >= v[3])
            {
                continue;
            }

            // We store the currentRemaining K after spending K (if required) into the visited matrix.
            visited[x][y] = v[3];

            // Push the adjacent nodes in the queue.
            q.push({x + 1, y, v[2] + 1, v[3]});
            q.push({x - 1, y, v[2] + 1, v[3]});
            q.push({x, y + 1, v[2] + 1, v[3]});
            q.push({x, y - 1, v[2] + 1, v[3]});
        }

        return -1;
    }
};
