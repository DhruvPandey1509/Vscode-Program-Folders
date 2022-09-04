#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    map<string, vector<int>> m;
    vector<int> diffWaysToCompute(string exp)
    {

        if (m.find(exp) != m.end())
            return m[exp];

        vector<int> left, right, res;
        for (int i = 0; i < exp.size(); i++)
        {
            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*')
            {
                string in_left = exp.substr(0, i);
                string in_right = exp.substr(i + 1);
                left = diffWaysToCompute(in_left);
                right = diffWaysToCompute(in_right);
            }

            for (auto l : left)
            {
                for (auto r : right)
                {
                    if (exp[i] == '+')
                        res.push_back(l + r);
                    else if (exp[i] == '-')
                        res.push_back(l - r);
                    else if (exp[i] == '*')
                        res.push_back(l * r);
                }
            }
        }

        if (!res.size())
            res.push_back(stoi(exp));
        return m[exp] = res;
    }
};
