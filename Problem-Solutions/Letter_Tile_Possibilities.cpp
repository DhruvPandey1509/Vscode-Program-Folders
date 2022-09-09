#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    set<string> res;
    unordered_map<int, bool> visited;
    void solve(string tiles, string s)
    {
        res.insert(s);
        for (int i = 0; i < tiles.size(); i++)
        {
            if (visited[i])
                continue;

            s.push_back(tiles[i]);
            visited[i] = true;

            solve(tiles, s);

            s.pop_back();
            visited[i] = false;
        }
    }
    int numTilePossibilities(string tiles)
    {
        for (int i = 0; i < tiles.length(); i++)
        {
            visited[i] = false;
        }

        solve(tiles, " ");

        return res.size() - 1;
    }
};
