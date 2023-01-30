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
    ListNode *removeNodes(ListNode *head)
    {
        vector<int> v;
        ListNode *temp = head;
        v.push_back(temp->val);
        temp = temp->next;
        while (temp != NULL)
        {
            while (v.size() && temp->val > v.back())
            {
                v.pop_back();
            }
            v.push_back(temp->val);
            temp = temp->next;
        }
        ListNode *res = new ListNode(v[0]);
        temp = res;
        for (int i = 1; i < v.size(); i++)
        {
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return res;
    }
};
