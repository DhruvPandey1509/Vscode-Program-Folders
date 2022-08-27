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
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *prev = NULL, *next = head->next;
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> v;
        stack<int> st;
        head = reverseList(head);

        while (head)
        {
            if (st.empty())
            {
                v.push_back(0);
                st.push(head->val);
                head = head->next;
            }
            else if (st.top() > head->val)
            {
                v.push_back(st.top());
                st.push(head->val);
                head = head->next;
            }
            else
            {
                st.pop();
            }
        }

        reverse(v.begin(), v.end());
        return v;
    }
};
