#include "bits/stdc++.h"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reorderList(ListNode *head)
    {

        if (!head || head->next == NULL || head->next->next == NULL)
            return;

        deque<int> dq;
        ListNode *curr = head;
        bool toggle = true;

        while (curr)
        {
            dq.push_back(curr->val);
            curr = curr->next;
        }

        curr = head;

        while (curr)
        {
            if (toggle)
            {
                curr->val = dq.front();
                dq.pop_front();
            }
            else
            {
                curr->val = dq.back();
                dq.pop_back();
            }

            toggle = !toggle;
            curr = curr->next;
        }
    }
};