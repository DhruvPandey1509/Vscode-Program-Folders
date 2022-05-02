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
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (!head || !head->next)
            return head;

        ListNode *temp = head;
        ListNode *res = head;
        while (head && head->next)
        {
            temp = head->next;
            while (temp != NULL && temp->val == head->val)
            {
                ListNode *todelete = temp;
                head->next = temp->next;
                temp = head->next;
                delete todelete;
            }
            head = head->next;
        }

        return res;
    }
};