#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> res(n);

        //stack of pair
        //monotonous decreasing stack
        stack<pair<int, int>> st; // first = price , second = span
        int span;
        res[0] = 1;
        st.push({price[0], res[0]});

        for (int i = 1; i < n; i++)
        {
            span = 1;
            if (price[i] < price[i - 1])
            {
                res[i] = span;
                st.push({price[i], span});
            }
            else
            {
                while (!st.empty() && st.top().first <= price[i])
                {
                    span += st.top().second;
                    st.pop();
                }
                st.push({price[i], span});
                res[i] = span;
            }
        }

        return res;
    }
};