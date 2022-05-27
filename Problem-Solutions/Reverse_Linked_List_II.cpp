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
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nxt = head;

        while (curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        if (head == NULL || head->next == NULL || left == right)
            return head;

        ListNode *temp = head;
        ListNode *prev = temp;
        int count = 1;
        while (temp != NULL and count != left)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }

        ListNode *node = temp;

        while (temp != NULL and count != right)
        {
            temp = temp->next;
            count++;
        }

        ListNode *nxt = temp->next;
        temp->next = NULL;

        ListNode *rev = reverse(node);

        node->next = nxt;

        if (left != 1)
        {
            prev->next = rev;
        }
        else
        {
            head = rev;
        }

        return head;
    }
};