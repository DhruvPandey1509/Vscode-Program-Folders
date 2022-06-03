#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *merge(Node *l1, Node *l2)
    {
        Node *temp = new Node(-1);
        Node *l3 = temp;

        while (l1 and l2)
        {
            if (l1->data < l2->data)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }

            temp = temp->next;
        }
        while (l1)
        {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }
        while (l2)
        {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }

        return l3->next;
    }
    // Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int k)
    {
        if (k == 1)
            return arr[0];

        if (k == 2)
            return merge(arr[0], arr[1]);
        priority_queue<Node *> q;

        for (int i = 0; i < k; i++)
        {
            q.push(arr[i]);
        }

        while (true)
        {
            Node *l1 = q.top();
            q.pop();

            if (q.empty())
                return l1;

            Node *l2 = q.top();
            q.pop();

            Node *l3 = merge(l1, l2);
            q.push(l3);
        }
    }
};