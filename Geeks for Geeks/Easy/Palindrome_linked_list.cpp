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

// class Solution{
//   public:
//   Node *reverse(Node *head)
//     {
//         if (head == NULL || head->next == NULL)
//         {
//             return head;
//         }

//         Node *prev = NULL;
//         Node *curr = head;
//         Node *nxt = head;

//         while (curr != NULL)
//         {
//             nxt = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nxt;
//         }
//         return prev;
//     }
//    int countNodes(Node *head)
//     {
//         int count = 0;
//         while(head != NULL)
//         {
//             count++;
//             head = head->next;
//         }

//         return count;
//     }
//     //Function to check whether the list is palindrome.
//     bool isPalindrome(Node *head)
//     {
//         if(head->next == NULL) return true;

//         int count = countNodes(head);

//         Node* temp = head;
//         int k = 1;
//             while(temp != NULL)
//             {
//                 k++;
//                 temp = temp->next;
//                 if(k == count/2)
//                 {
//                     temp->next = reverse(temp->next);
//                     break;
//                 }
//             }
//             Node *rt = temp->next;
//             temp = head;
//             while(rt != NULL)
//             {
//                 if(temp->data != rt->data) return false;

//                 temp = temp->next;
//                 rt = rt->next;
//             }

//             return true;
//     }
// };