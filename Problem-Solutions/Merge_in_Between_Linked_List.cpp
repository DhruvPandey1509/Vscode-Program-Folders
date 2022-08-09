#include "bits/stdc++.h"
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *tail1 = list1;
        ListNode *tail2 = list2;
        int count = 0;
        while (count < b)
        {
            tail1 = tail1->next;
            count++;
        }
        while (tail2->next != NULL)
        {
            tail2 = tail2->next;
        }
        tail2->next = tail1->next;
        
        count = 1;
        ListNode *temp = list1;
        while (count < a)
        {
            temp = temp->next;
            count++;
        }
        temp->next = list2;

        return list1;
    }
};