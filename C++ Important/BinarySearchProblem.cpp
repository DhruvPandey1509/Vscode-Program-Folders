#include<iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int mid, int *a, int n, int k)
{
   int pos = a[0], elements = 1;
   for(int i = 1 ; i < n ; i++)
   {
       if(a[i]-pos >= mid)
       {
           pos = a[i]; 
           elements++;
           if(elements == k)
           {
               return true;
           }
       }
   }
   return false;
}
int largestMinDistance(int *a, int n, int k) //n = size, k = required numbers in group
{
    sort(a, a+n);

    int result = -1;
    int left = 1, right = a[n-1];

    while(left < right)
    {
        int mid = left + (right-left)/2;
        if(isFeasible(mid, a, n, k))
        {
            result = max(result, mid);
            left = mid+1;
        }
        else
        {
            right = mid;
        }
    }

    return result;
}
int main()
{
    int a[] = {1,2,8,4,9}; 
    int n = 5, k = 3;
    cout<<"Largest minimum distance is : "<<largestMinDistance(a,n,k)<<endl;
    
    return 0;
}