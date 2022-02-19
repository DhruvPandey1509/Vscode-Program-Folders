#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareBoxes(vector<int> b1, vector<int> b2)
{
    return b1[2] > b2[2];
}
bool canPlace(vector<int> b1, vector<int> b2)
{
    if (b1[0] > b2[0] and b1[1] > b2[1] and b1[2] > b2[2])
    {
        return true;
    }
    return false;
}
int boxStacking(vector<vector<int>> boxes)
{
    // 1.Sorting
    sort(boxes.begin(), boxes.end(), compareBoxes);

    // 2. DP
    int n = boxes.size();
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        dp[i] = boxes[i][2]; // height of the ith box
    }

    for (int i = 1; i < n; i++)
    {
        // check for all boxes whose index is less then i
        for (int j = 0; j < i; j++)
        {
            if (canPlace(boxes[j], boxes[i]))
            {
                int curr_height = boxes[i][2];
                dp[i] = max(dp[i], dp[j] + curr_height);
                // if(dp[j] + curr_height > dp[i])
                // {
                //     dp[i] = dp[j] + curr_height;
                // }
            }
        }
    }
    int max_height = 0;
    for (int i = 0; i < n; i++)
    {
        max_height = max(max_height, dp[i]);
    }

    return max_height;
}

int main()
{
    vector<vector<int>> boxes = {
        {2, 1, 2},
        {3, 2, 3},
        {2, 2, 8},
        {2, 3, 4},
        {2, 2, 1},
        {4, 4, 5}};

    cout << boxStacking(boxes) << endl;

    return 0;
}