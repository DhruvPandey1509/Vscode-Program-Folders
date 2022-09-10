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
    ListNode *reverse(ListNode *root)
    {
        if (root == NULL)
            return root;

        ListNode *prev = NULL;
        ListNode *curr = root;
        ListNode *nxt = curr;

        while (curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverse(l1);
        l2 = reverse(l2);

        int val = 0;
        ListNode *l3 = new ListNode(-1);
        ListNode *temp = l3;
        while (l1 != NULL and l2 != NULL)
        {
            int sum = l1->val + l2->val + val;
            val = sum / 10;
            sum %= 10;
            temp->next = new ListNode(sum);
            temp = temp->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL)
        {
            int sum = l1->val + val;
            val = sum / 10;
            sum %= 10;
            temp->next = new ListNode(sum);
            l1 = l1->next;
            temp = temp->next;
        }

        while (l2 != NULL)
        {
            int sum = l2->val + val;
            val = sum / 10;
            sum %= 10;
            temp->next = new ListNode(sum);
            l2 = l2->next;
            temp = temp->next;
        }

        if (val != 0)
        {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
        return reverse(l3->next);
    }
};