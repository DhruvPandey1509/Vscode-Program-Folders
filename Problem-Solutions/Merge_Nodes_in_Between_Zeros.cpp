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

// Brute Force Approach
class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {

        ListNode *start = head;
        ListNode *curr = head->next;

        while (start->next != NULL and curr != NULL)
        {
            int data = 0;
            while (curr != NULL and curr->val != 0)
            {
                data += curr->val;
                curr = curr->next;
            }
            start->next->val = data;
            start->next->next = curr;
            start = curr;
            curr = curr->next;
        }
        ListNode *resHead = new ListNode(-1);

        curr = head;

        while (curr != NULL)
        {
            if (curr->val != 0)
            {
                if (resHead->val == -1)
                {
                    resHead->val = curr->val;
                    start = resHead;
                }
                else
                {
                    start->next = curr;
                    start = start->next;
                }
            }
            curr = curr->next;
        }
        start->next = NULL;
        return resHead;
    }
};
// Shorter Approach
class Solution1
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        head = head->next;
        ListNode *st = head;
        while (st != NULL)
        {
            ListNode *en = st;
            int sum = 0;
            while (en->val != 0)
            {
                sum += en->val;
                en = en->next;
            }
            st->val = sum;
            st->next = en->next;
            st = st->next;
        }

        return head;
    }
};
