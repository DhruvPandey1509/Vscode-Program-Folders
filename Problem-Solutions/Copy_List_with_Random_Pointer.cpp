#include "bits/stdc++.h"
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        if (head == NULL)
            return head;

        // creating and inserting new copy Node in between of the original node
        Node *curr = head, *temp;
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }

        // setting random pointers of the copy node
        curr = head;
        while (curr != NULL && curr->next != NULL)
        {
            curr->next->random = (curr->random != NULL) ? curr->random->next : NULL;
            curr = (curr->next) ? curr->next->next : curr->next;
        }

        // separating both the linked lists
        Node *org = head;
        Node *copy = head->next;
        Node *res = copy; // head of copy list to return;
        while (org != NULL && copy != NULL)
        {
            org->next = (org->next != NULL) ? org->next->next : org->next;
            copy->next = (copy->next != NULL) ? copy->next->next : copy->next;
            org = org->next;
            copy = copy->next;
        }
        return res;
    }
};