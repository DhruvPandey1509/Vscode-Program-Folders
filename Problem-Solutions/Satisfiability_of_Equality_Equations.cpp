#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    vector<int> parent;
    vector<int> r;
    int findParent(int x)
    {
        if (parent[x] == x)
            return x;

        return findParent(parent[x]);
    }

    void Union(int x, int y)
    {
        if (r[x] < r[y])
        {
            r[y] += r[x];
            parent[x] = y;
        }
        else
        {
            r[x] += r[y];
            parent[y] = x;
        }
    }

    bool equationsPossible(vector<string> &equations)
    {
        parent.resize(26);
        r.resize(26);
        for (int i = 0; i < 26; i++)
        {
            parent[i] = i;
            r[i] = 0;
        }

        for (auto eq : equations)
        {
            if (eq[1] == '=')
            {
                int a = findParent(eq[0] - 'a');
                int b = findParent(eq[3] - 'a');
                Union(a, b);
            }
        }

        for (auto eq : equations)
        {
            if (eq[1] == '!')
            {
                int a = findParent(eq[0] - 'a');
                int b = findParent(eq[3] - 'a');

                if (a == b)
                    return false;
            }
        }

        return true;
    }
};
