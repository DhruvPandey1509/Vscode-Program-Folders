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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lesser = new ListNode(0);
        ListNode *greater = new ListNode(0);

        ListNode *less = lesser;
        ListNode *great = greater;

        ListNode *temp = head;
        while (temp != NULL)
        {
            if (temp->val < x)
            {
                less->next = temp;
                less = less->next;
            }
            else
            {
                great->next = temp;
                great = great->next;
            }
            temp = temp->next;
        }
        great->next = NULL;
        less->next = greater->next;
        return lesser->next;
    }
};