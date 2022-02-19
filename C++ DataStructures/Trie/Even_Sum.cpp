/*
There are N integers in an array A.

Two players take turns alternatively in placing signs (+ or -) before them, and then they all are added.
The sign can be placed before any element of the array that has not been assigned a sign yet.
All elements must be assigned a sign.

Player 1 wins if the resulting sum is even, else player 2 wins. Find out who shall win if they both play optimally.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains 2 lines of input.
First line contains a single integer N, size of the array.
Second line contains N space separated integers - A1,A2,…,AN, denoting the array elements.
Output:
For each testcase, output in a single line "1", if the first person wins or "2" if the second person wins.

Constraints
1≤T≤10
1≤N≤105
1≤Ai≤109

Subtasks
Subtask #1 (100 points): Original constraints

Sample Input 1
3
2
1 2
3
1 1 2
3
1 2 4

Sample Output 1
2
1
2
*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
    }

    return 0;
}