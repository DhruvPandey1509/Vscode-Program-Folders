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

Node *sortedMerge(Node *head1, Node *head2)
{
    Node *temp = new Node(-1);
    Node *l3 = temp;

    while (head1 and head2)
    {
        if (head1->data < head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }

        temp = temp->next;
    }

    while (head1)
    {
        temp->next = head1;
        head1 = head1->next;
        temp = temp->next;
    }

    while (head2)
    {
        temp->next = head2;
        head2 = head2->next;
        temp = temp->next;
    }

    return l3->next;
}