#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int lastStoneWeight(vector<int> &v)
    {
        priority_queue<int> p;
        for (int i = 0; i < v.size(); i++)
        {
            p.push(v[i]);
        }
        int i = 0;
        while (!p.empty())
        {
            int y = p.top();
            p.pop();
            if (p.empty())
            {
                return y;
            }

            int x = p.top();
            p.pop();
            p.push(y - x);
        }

        return 0;
    }
};