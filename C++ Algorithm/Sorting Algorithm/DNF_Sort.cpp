#include <iostream>
using namespace std;

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void DnfSort(int *arr, int high)
{
    int low = 0, mid = 0;

    while (mid < high)
    {
        if (arr[mid] == 0)
        {
            swap(arr, low, mid);
            low++;
            mid++;
        }

        if (arr[mid] == 1)
        {
            mid++;
        }

        if (arr[mid] == 2)
        {
            swap(arr, mid, high);
            high--;
            mid++;
        }
    }
}
void display(int *arr, int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[] = {1, 0, 2, 1, 0, 1, 1, 2, 0, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    DnfSort(arr, n-1);
    display(arr, n);
    return 0;
}
