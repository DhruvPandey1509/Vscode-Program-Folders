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
    ListNode *swapNodes(ListNode *head, int k)
    {

        ListNode *temp1 = head, *temp2 = head;

        int len = 0;
        while (temp1)
        {
            len++;
            temp1 = temp1->next;
        }
        temp1 = head;

        for (int i = 0; i < k - 1; i++)
        {
            temp1 = temp1->next;
        }

        for (int i = 0; i < len - k; i++)
        {
            temp2 = temp2->next;
        }

        int temp = temp1->val;
        temp1->val = temp2->val;
        temp2->val = temp;

        return head;
    }
};