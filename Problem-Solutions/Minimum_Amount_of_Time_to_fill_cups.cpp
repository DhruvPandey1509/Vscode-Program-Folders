#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int fillCups(vector<int> &amount)
    {

        priority_queue<int> p;
        p.push(amount[0]);
        p.push(amount[1]);
        p.push(amount[2]);
        int count = 0;

        while (p.top() != 0)
        {
            int n1 = p.top();
            p.pop();
            int n2 = p.top();
            p.pop();
            n1--;
            n2--;
            p.push(n1);
            p.push(n2);
            count++;
        }

        return count;
    }
};