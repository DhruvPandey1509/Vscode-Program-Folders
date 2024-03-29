#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];

        return a[0] < b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {

        int n = people.size();
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(n, vector<int>(2, -1));

        for (int i = 0; i < n; i++)
        {
            int count = people[i][1];
            for (int j = 0; j < n; j++)
            {
                if (res[j][0] == -1 and count == 0)
                {
                    res[j][0] = people[i][0];
                    res[j][1] = people[i][1];
                    break;
                }
                else if (res[j][0] == -1 || res[j][0] >= people[i][0])
                    count--;
            }
        }

        return res;
    }
};
