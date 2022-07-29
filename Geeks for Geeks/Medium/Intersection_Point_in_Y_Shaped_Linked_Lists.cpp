#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
        return -1;

    Node *temp = head2;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head2;

    Node *slow = head1;
    Node *fast = head1;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
            break;
    }

    slow = head1;
    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow->data;
}