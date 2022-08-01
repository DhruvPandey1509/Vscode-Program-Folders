#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> merge(vector<int> a, vector<int> b)
    {
        int n1 = a.size();
        int n2 = b.size();

        vector<int> res(n1 + n2);
        int i = 0, j = 0, k = 0;

        while (i < n1 and j < n2)
        {
            if (a[i] < b[j])
            {
                res[k] = a[i];
                i++;
            }
            else
            {
                res[k] = b[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            res[k] = a[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            res[k] = b[j];
            j++;
            k++;
        }

        return res;
    }
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p;

        for (int i = 0; i < arr.size(); i++)
        {
            p.push(arr[i]);
        }

        vector<int> res;

        while (!p.empty())
        {
            vector<int> v1 = p.top();
            p.pop();
            if (p.empty())
            {
                res = v1;
                break;
            }
            vector<int> v2 = p.top();
            p.pop();
            p.push(merge(v1, v2));
        }

        return res;
    }
};
