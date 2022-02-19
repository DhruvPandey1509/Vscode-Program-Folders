#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPalindrome(int num)
{
    int revn = 0;
    int temp = num;
    int rem = 0;

    while (num > 0)
    {
        rem = num % 10;
        revn = revn * 10 + rem;
        num /= 10;
    }

    if (revn == temp)
    {
        return true;
    }

    return false;
}

int findPalindromicSubarray(vector<int> arr, int k)
{
    int num = 0;

    for (int i = 0; i < k; i++)
    {
        num = num * 10 + arr[i];
    }

    if (isPalindrome(num))
    {
        return 0;
    }

    for (int i = k; i < arr.size(); i++)
    {
        num = (num % (int)pow(10, k - 1)) * 10 + arr[i];
        if (isPalindrome(num))
        {
            return i - k + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> v = {2, 3, 5, 1, 1, 5};
    int k = 4;

    int res = findPalindromicSubarray(v, k);
    if (res == -1)
    {
        cout << "No Palindrom exists in Subarray." << endl;
    }
    else
    {
        cout << "Palindrome exists in Subarray" << endl;
        for (int i = res; i < res + k; i++)
        {
            cout << v[i] << " ";
        }
    }

    return 0;
}