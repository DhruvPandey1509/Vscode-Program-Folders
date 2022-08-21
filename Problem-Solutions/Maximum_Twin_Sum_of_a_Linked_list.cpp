#include "bits/stdc++.h"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        vector<int> v;

        while (head != NULL)
        {
            v.push_back(head->val);
            head = head->next;
        }

        int n = v.size();
        if (n == 2)
        {
            return v[0] + v[1];
        }

        int max_sum = 0;
        for (auto i = 0; i < (n / 2); i++)
        {
            max_sum = max(max_sum, v[i] + v[n - 1 - i]);
        }

        return max_sum;
    }
};