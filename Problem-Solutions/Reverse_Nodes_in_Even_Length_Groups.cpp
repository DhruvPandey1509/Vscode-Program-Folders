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
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *curr = head, *temp;
        int sz = 1;
        while (curr)
        {
            temp = curr;
            vector<int> v;
            for (int i = 0; i < sz and curr != NULL; i++)
            {
                v.push_back(curr->val);
                curr = curr->next;
            }

            if (v.size() % 2 == 0)
            {
                reverse(v.begin(), v.end());
                for (int i = 0; i < v.size(); i++)
                {
                    temp->val = v[i];
                    temp = temp->next;
                }
            }

            sz++;
        }

        return head;
    }
};
