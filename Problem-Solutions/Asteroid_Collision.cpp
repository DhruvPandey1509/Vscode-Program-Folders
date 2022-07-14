#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &a)
    {
        vector<int> res;
        stack<int> st;
        for (int i = 0; i < a.size(); i++)
        {
            int n = a[i];
            if (n > 0)
            {
                st.push(n);
            }
            else
            {
                if (st.empty() || st.top() < 0)
                    st.push(n);

                else
                {
                    while (1)
                    {
                        if (st.empty())
                        {
                            st.push(n);
                            break;
                        }
                        int num = st.top();
                        if (num < 0)
                        {
                            st.push(n);
                            break;
                        }
                        if ((-1) * n < num)
                        {
                            break;
                        }
                        else if ((-1) * n == num)
                        {
                            st.pop();
                            break;
                        }
                        else
                        {
                            st.pop();
                            continue;
                        }
                    }
                }
            }
        }

        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};