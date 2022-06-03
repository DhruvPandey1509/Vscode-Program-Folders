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

bool isCircular(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (slow && fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}