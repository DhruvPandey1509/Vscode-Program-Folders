#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    static bool sortFunc(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>> &courses)
    {

        int len = courses.size();
        sort(courses.begin(), courses.end(), sortFunc);

        priority_queue<int> pq;
        int time = 0;
        int count = 0;

        for (int i = 0; i < len; i++)
        {
            if (time + courses[i][0] <= courses[i][1])
            {
                count++;
                time += courses[i][0];
                pq.push(courses[i][0]);
            }
            else if (!pq.empty() && pq.top() > courses[i][0])
            {
                time -= (pq.top() - courses[i][0]);
                pq.pop();
                pq.push(courses[i][0]);
            }
        }

        return count;
    }
};

//Same Way but simpler code
class Solution1 {
public:
    
    static bool sortFunc(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin(), courses.end(), sortFunc);
        
        priority_queue<int> pq;
        int time = 0;
        
        for(auto c : courses)
        {
            time += c[0];
            pq.push(c[0]);
            
            if(time > c[1])
            {
                time -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
        
    }
};