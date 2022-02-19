#include"bits/stdc++.h"
using namespace std;
vector<int> solution(vector<int> &nums, int t)
{
	vector<pair<int, int>> v;
	for(int i = 0 ; i < nums.size(); i++)
	{
		v.push_back(make_pair(nums[i],i)); //nums[i] denotes the value and i denotes the index at which the value is.
	}
	sort(v.begin(), v.end()); 

	int st = 0;           //start pointer setting at 0;
	int en = nums.size()-1;    //end pointer setting at last index
	int sum = 0;
    vector<int> v1;   //vector where we will pass the start and end index of the desired values and return back to the main function.

	while(st < en)       //as long as start pointer is less than end pointer
	{
		sum = v[st].first + v[en].first;

		if(sum == t)
		{
           v1.push_back(v[st].second); //index is at second place in vector
		   v1.push_back(v[en].second);
		   break;
		}

		else if(sum > t)
		{
			en--;
		}
		else if(sum < t)
		{
			st++;
		}
	}
	return v1;

	
}
int main()
{
	int target = 9;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	vector<int> v = solution(nums, target);
    for(int &i : v)
	{
		cout<<i<<" ";
	}
	return 0;
}