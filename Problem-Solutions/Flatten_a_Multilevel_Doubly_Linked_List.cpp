#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (head == NULL)
            return head;

        stack<Node *> st;
        Node *temp = head;

        while (!st.empty() || temp != NULL)
        {
            if (temp->child != NULL)
            {
                if (temp->next)
                    st.push(temp->next);

                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = NULL;
            }
            if (!temp->next && !st.empty())
            {
                Node *top = st.top();
                st.pop();
                temp->next = top;
                top->prev = temp;
            }
            temp = temp->next;
        }

        return head;
    }
};