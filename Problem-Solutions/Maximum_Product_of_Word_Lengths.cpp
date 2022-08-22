#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        vector<unordered_set<char>> st;

        for (string word : words)
        {
            unordered_set<char> temp;
            for (char c : word)
            {
                temp.insert(c);
            }

            st.push_back(temp);
        }
        int res = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                bool flag = false;
                for (auto val : st[i])
                {
                    if (st[j].find(val) != st[j].end())
                    {
                        flag = true;
                        break;
                    }
                }

                if (!flag)
                {
                    int product = words[i].length() * words[j].length();
                    res = max(res, product);
                }
            }
        }
        return res;
    }
};