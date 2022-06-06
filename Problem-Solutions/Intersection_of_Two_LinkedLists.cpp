#include "bits/stdc++.h"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *hA, ListNode *hB)
    {

        unordered_map<ListNode *, int> m;
        while (hA)
        {
            m[hA]++;
            hA = hA->next;
        }

        while (hB)
        {
            if (m[hB] > 0)
            {
                return hB;
            }
            hB = hB->next;
        }

        return hB;
    }
};