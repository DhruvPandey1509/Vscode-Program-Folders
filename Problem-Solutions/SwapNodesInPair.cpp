#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    ListNode *swapPairs(ListNode *head)
    {

        if (!head || !(head->next))
            return head;

        ListNode *n1 = head, *n2 = head->next;

        while (n1->next != NULL && n2 != NULL)
        {
            swap(&(n1->val), &(n2->val));
            if (n2->next == NULL)
            {
                break;
            }

            n1 = n2->next;
            n2 = n1->next;
        }

        return head;
    }
};