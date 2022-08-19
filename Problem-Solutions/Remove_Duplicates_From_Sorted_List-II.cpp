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
        if (head == NULL)
            return NULL;

        map<int, int> m;
        set<int> s;

        while (head != NULL)
        {
            if (m.find(head->val) != m.end())
            {
                m[head->val]++;
                s.insert(head->val);
            }
            else
            {
                m[head->val]++;
            }
            head = head->next;
        }

        for (auto &i : s)
        {
            m.erase(i);
        }
        if (m.size() == 0)
            return NULL;
        ListNode *head1 = new ListNode(-1000);
        ListNode *temp;

        for (auto i : m)
        {
            if (head1->val == -1000)
            {
                head1->val = i.first;
                temp = head1;
            }
            else
            {
                temp->next = new ListNode(i.first);
                temp = temp->next;
            }
        }

        temp->next = NULL;

        return head1;
    }
};