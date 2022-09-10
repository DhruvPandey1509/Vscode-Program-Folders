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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (auto i : nums)
            m[i]++;

        int count = 0;
        int res = 0;

        while (head != NULL)
        {
            if (m.find(head->val) != m.end())
            {
                count++;
            }
            else
            {
                if (count >= 1)
                    res++;
                count = 0;
            }
            head = head->next;
        }
        if (count >= 1)
            res++;
        return res;
    }
};