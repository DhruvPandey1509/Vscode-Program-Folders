#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums2.size();
        unordered_map<int, int> m; // key = nums2[idx] value = idx
        for (int i = 0; i < n; i++)
        {
            m[nums2[i]] = i;
        }

        stack<int> st;          // for storing the index of elements and to compare with nums2 element
        vector<int> res(n, -1); // stores the next greater element for nums2 index wise i.e res[idx] = next greater element then the element stored at nums2[idx]
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and nums2[st.top()] < nums2[i])
            {
                res[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        vector<int> ans(nums1.size(), -1);

        for (int i = 0; i < nums1.size(); i++)
        {
            ans[i] = res[m[nums1[i]]];
        }
        return ans;
    }
};