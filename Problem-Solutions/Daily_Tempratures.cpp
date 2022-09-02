#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temp)
    {

        int n = temp.size();
        vector<int> res(n, 0);

        stack<pair<int, int>> st; // pair : [temp, index]

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and temp[i] > st.top().first)
            {
                int num = st.top().first;
                int idx = st.top().second;
                res[idx] = i - idx;
                st.pop();
            }
            st.push({temp[i], i});
        }

        return res;
    }
};