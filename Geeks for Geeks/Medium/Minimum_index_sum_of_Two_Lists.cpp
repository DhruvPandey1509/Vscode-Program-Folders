#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> m;
        vector<string> res;
        int n1 = list1.size();

        for (int i = 0; i < list2.size(); i++)
        {
            m[list2[i]] = i;
        }

        int idx = INT_MAX;
        int i = 0;

        while (i < n1)
        {
            if (m.find(list1[i]) != m.end())
            {
                int sum = i + m[list1[i]];
                if (sum < idx)
                {
                    while (res.size() > 0)
                    {
                        res.pop_back();
                    }

                    res.push_back(list1[i]);
                    idx = sum;
                }
                else if (idx == sum)
                {
                    res.push_back(list1[i]);
                }
            }
            i++;
        }

        return res;
    }
};