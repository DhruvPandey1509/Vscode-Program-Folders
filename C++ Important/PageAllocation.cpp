#include <iostream>
#include <climits>
using namespace std;

bool isFeasible(int *a, int n, int m, int min) // min = minimum possible maximum pages
{
    int studentsRequired = 1, sum = 0; //sum = number of pages that have been allocated to the student so far;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > min) //if the number of pages we are trying to allocate is more then the minimum possible maximum pages
        {
            return false;
        }
        else if (sum + a[i] > min) //if the current pages is more then the minimum possible maximum pages and we cannot allocate any more
        {                          //pages to the current student :. we will start allocating pages to the next student.
            studentsRequired++;
            sum = a[i];
            if (studentsRequired > m) //if it is more than the total students
            {
                return false;
            }
        }
        else
        {
            sum += a[i]; // we can continue to allot pages to the current student therefore increasing the number of pages.
        }
    }

    return true;
}

int allocateMinimum(int *a, int n, int m) //n = no. of diff books,  m = no. of diff students, a = contains pages in books.
{
    int sum = 0;
    if (n < m)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    int start = 0, end = sum, ans = INT_MAX;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isFeasible(a, n, m, mid))
        {
            ans = min(ans, mid);
            end = mid - 1; //checking in the left half
        }
        else
        {
            start = mid + 1; //checking in the right half
        }
    }
    return ans;
}

int main()
{
    int a[] = {12, 34, 67, 90};
    int n = 4, m = 2;
    cout << "Minimum Number of Pages : " << allocateMinimum(a, n, m) << endl;

    return 0;
}