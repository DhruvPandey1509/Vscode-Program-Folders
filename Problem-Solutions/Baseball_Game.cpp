#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {

        vector<int> res;

        for (int i = 0; i < ops.size(); i++)
        {
            int n = res.size();
            if (ops[i] == "C")
                res.pop_back();
            else if (ops[i] == "D")
                res.push_back(2 * res[n - 1]);
            else if (ops[i] == "+")
                res.push_back(res[n - 1] + res[n - 2]);
            else
                res.push_back(stoi(ops[i]));
        }

        int sum = 0;

        for (int i = 0; i < res.size(); i++)
        {
            sum += res[i];
        }

        return sum;
    }
};