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
    int countNodes(Node *head)
    {
        if (!head)
            return 0;
        if (!head->next)
            return 1;

        int count = 0;
        while (head)
        {
            count++;
            head = head->next;
        }

        return count;
    }
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        int count = countNodes(head);

        count = count / 2;

        while (count--)
        {
            head = head->next;
        }

        return head->data;
    }
};