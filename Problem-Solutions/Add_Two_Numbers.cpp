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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *l3 = new ListNode();
        ListNode *temp = l3;
        int carry = 0;

        while (l1 != NULL && l2 != NULL)
        {
            int num = l1->val + l2->val;

            temp->next = new ListNode((carry + num) % 10);

            if (num + carry >= 10)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }

        while (l1 != NULL)
        {
            int num = l1->val;
            temp->next = new ListNode((carry + num) % 10);
            carry = (carry + num) / 10;
            l1 = l1->next;
            temp = temp->next;
        }
        while (l2 != NULL)
        {
            int num = l2->val;
            temp->next = new ListNode((carry + num) % 10);
            carry = (carry + num) / 10;
            l2 = l2->next;
            temp = temp->next;
        }

        if (carry != 0)
        {
            temp->next = new ListNode(carry);
        }

        return l3->next;
    }
};