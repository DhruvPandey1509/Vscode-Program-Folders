// Ques No 213
// Difficulty Medium

#include <iostream>
#include <vector>
using namespace std;
int helper(vector<int> nums, int st, int en)
{
    vector<int> dp(en + 1, 0);
    dp[st] = nums[st];
    dp[st + 1] = max(nums[st], nums[st + 1]);

    for (int i = st + 2; i <= en; i++)
    {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[en];
}
int rob(vector<int> &nums)
{

    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    if (n == 2)
    {
        return max(nums[0], nums[1]);
    }
    //     we will return the max value out of two
    //         1case is including first house and excluding last house
    //         2nd case is including last house and excluding first house
    return max(helper(nums, 0, n - 2),  helper(nums, 1, n - 1));
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &i : nums)
    {
        cin >> i;
    }

    cout << rob(nums) << endl;

    return 0;
}