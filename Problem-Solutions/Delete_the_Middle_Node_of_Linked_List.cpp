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
    int countNodes(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head and head->next == NULL)
        {
            return NULL;
        }
        // else if(head and head->next and head->next->next == NULL)
        // {
        //     ListNode *todelete = head->next;
        // }

        int count = countNodes(head);
        ListNode *temp = head;
        ListNode *todelete = head->next;

        count = count / 2;
        count--;
        while (count--)
        {
            temp = temp->next;
            todelete = todelete->next;
        }

        temp->next = todelete->next;
        delete todelete;

        return head;
    }
};