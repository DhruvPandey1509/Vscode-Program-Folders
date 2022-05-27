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
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *prev = NULL;
        Node *curr = head;
        Node *nxt = head;

        while (curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if (head->next == NULL)
            return true;

        Node *slow = head;
        Node *fast = head;

        while (fast->next != NULL and fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = reverse(slow->next);
        Node *mid = slow->next;
        Node *start = head;

        while (mid != NULL)
        {
            if (mid->data != start->data)
                return false;

            mid = mid->next;
            start = start->next;
        }

        return true;
    }
};