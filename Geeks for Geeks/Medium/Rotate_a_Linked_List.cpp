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

class Solution
{
public:
    int countNodes(Node *head)
    {
        int count = 0;
        while (head)
        {
            count++;
            head = head->next;
        }

        return count;
    }
    // Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        if (head->next == NULL)
            return head;

        int n = countNodes(head);

        if (n == k)
            return head;

        k = k % n;
        Node *temp = new Node(-1); // temporary node traverse for resultant list
        Node *l3 = temp;           // resultant list will be at l3->next

        int count = 1;

        Node *dummyhead = head; // temporary node to traverse from head
        while (count < k)
        {
            dummyhead = dummyhead->next;
            count++;
        }

        temp->next = dummyhead->next;
        dummyhead->next = NULL;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = head;

        return l3->next;
    }
};