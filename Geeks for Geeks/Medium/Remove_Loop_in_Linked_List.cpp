#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        if (head == NULL)
        {
            return;
        }

        Node *slow = head;
        Node *fast = head;

        while (slow != NULL and fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }

        // No cycle
        if (slow != fast)
        {
            return;
        }
        slow = head;

        // case when the loop starts with the head
        if (slow == fast)
        {
            while (fast->next != slow)
            {
                fast = fast->next;
            }
        }
        else
        {
            while (fast->next != slow->next)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        fast->next = NULL;
    }
};