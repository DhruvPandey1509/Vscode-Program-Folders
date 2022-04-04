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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {

        vector<ListNode *> list(k, NULL);
        if (!head)
        {
            return list;
        }
        ListNode *st = head;
        int len = 0;
        while (st)
        {
            len++;
            st = st->next;
        }

        vector<int> v(k, 1);

        int temp = len % k;

        for (int i = 0; i < k; i++)
        {
            if (k < len)
            {
                v[i] = len / k;
                if (temp > 0)
                {
                    v[i]++;
                    temp--;
                }
            }
            else
            {
                if (i >= len)
                {
                    v[i] = 0;
                }
            }
        }

        int ind = 0;
        for (int i = 0; i < v.size() && v[i] != 0 && head; i++)
        {
            ListNode *h = head, *t = head;

            int n = 1;

            while (n < v[i] && t->next)
            {
                t = t->next;
                n++;
            }

            head = t->next;
            t->next = NULL;
            list[ind] = h;
            ind++;
        }

        return list;
    }
};