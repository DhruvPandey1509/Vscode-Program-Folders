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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (!head)
            return head;
        int len = 1;

        ListNode *tail = head;
        while (tail->next)
        {
            len++;
            tail = tail->next;
        }
        tail->next = head;
        k %= len;

        ListNode *newhead = NULL;
        for (int i = 0; i < len - k; i++)
        {
            tail = tail->next;
        }
        newhead = tail->next;
        tail->next = NULL;

        return newhead;
    }
};