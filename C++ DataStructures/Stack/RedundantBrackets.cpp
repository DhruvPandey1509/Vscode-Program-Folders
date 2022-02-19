#include <iostream>
#include <stack>
#include <algorithm>
#include<string>
using namespace std;

int main()
{
	string s;
	bool ans;
	cin>>s;
	stack<char> st;
    for(int i = 0 ; i < s.size(); i++)
	{
		if(s[i] == '(')
		{
			st.push(s[i]);
		}
		else if( s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
	    	st.push(s[i]);
		}
		else if(s[i] == ')')
		{
			if(st.top() == '(')
			{
				ans = true;
			}
			while(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
			{
              st.pop();
			}
            st.pop();
		}
	}

	cout<<ans<<endl;
	return 0;
}