#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    void ratInMaze(vector<vector<int>> &m, int r, int c, int n, string s, vector<string> &res)
    {
        if (r < 0 || c < 0 || r >= n || c >= n)
            return;

        if (m[r][c] != 1)
            return;

        if (r == n - 1 and c == n - 1)
        {
            res.push_back(s);
        }

        m[r][c] = -1;
        ratInMaze(m, r + 1, c, n, s + "D", res);
        ratInMaze(m, r, c + 1, n, s + "R", res);
        ratInMaze(m, r - 1, c, n, s + "U", res);
        ratInMaze(m, r, c - 1, n, s + "L", res);

        m[r][c] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> res;
        string s = "";
        ratInMaze(m, 0, 0, n, s, res);

        return res;
    }
};