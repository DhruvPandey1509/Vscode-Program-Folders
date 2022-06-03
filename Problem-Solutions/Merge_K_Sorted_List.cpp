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
    ListNode *mergeList(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = new ListNode(-1);
        ListNode *res = l3;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }

        while (l1 != NULL)
        {
            l3->next = l1;
            l1 = l1->next;
            l3 = l3->next;
        }

        while (l2 != NULL)
        {
            l3->next = l2;
            l2 = l2->next;
            l3 = l3->next;
        }

        return res->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        
        int n = lists.size();
        if (n == 0)
            return NULL;

        priority_queue<ListNode *> q;

        for (int i = 0; i < n; i++)
        {
            q.push(lists[i]);
        }

        while (1)
        {
            ListNode *l1 = q.top();
            q.pop();

            if (q.empty())
                return l1;

            ListNode *l2 = q.top();
            q.pop();

            ListNode *l3 = mergeList(l1, l2);
            q.push(l3);
        }
    }
};