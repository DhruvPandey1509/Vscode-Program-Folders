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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> v(m, vector<int>(n, -1));
        int sr = 0, sc = 0;
        int er = m - 1;
        int ec = n - 1;
        while (sr <= er && sc <= ec && head != NULL)
        {
            // first row
            for (int i = sc; i <= ec; i++)
            {
                if (head != NULL)
                    v[sr][i] = head->val;
                if (head == NULL)
                    break;
                head = head->next;
            }
            sr++;
            // last col
            for (int j = sr; j <= er; j++)
            {
                if (head != NULL)
                    v[j][ec] = head->val;
                if (head == NULL)
                    break;
                head = head->next;
            }
            ec--;
            // last row
            if (ec > sc)
            {
                for (int i = ec; i >= sc; i--)
                {
                    if (head != NULL)
                        v[er][i] = head->val;
                    if (head == NULL)
                        break;
                    head = head->next;
                }
                er--;
            }
            // first col
            if (er > sr)
            {
                for (int j = er; j >= sr; j--)
                {
                    if (head != NULL)
                        v[j][sc] = head->val;
                    if (head == NULL)
                        break;
                    head = head->next;
                }
                sc++;
            }
            if (head == NULL)
                break;
        }
        return v;
    }
};