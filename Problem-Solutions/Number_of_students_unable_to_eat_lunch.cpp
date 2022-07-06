#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n1 = students.size();
        int n2 = sandwiches.size();

        queue<int> p; // sandwiches
        queue<int> q; // students

        for (int i = 0; i < n2; i++)
        {
            p.push(sandwiches[i]);
        }

        for (int i = 0; i < n1; i++)
        {
            q.push(students[i]);
        }

        int k = 0;

        while (n1 > 0 and n2 > 0)
        {
            if (q.front() == p.front())
            {
                q.pop();
                p.pop();

                k = 0; // making k = 0 that means that sandwich acc to student taste is present and there may be more we have to check for

                n1--;
                n2--;
            }
            else
            {
                int stu = q.front();
                q.pop();
                q.push(stu);

                // k is keeping track that if we have already made all students move back and still no one accepts the sandwich it means no sandwich according to student taste is present , so we break out of the loop
                k++;

                if (k > q.size())
                {
                    break;
                }
            }
        }

        return q.size();
    }
};