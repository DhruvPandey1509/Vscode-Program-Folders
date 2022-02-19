#include"bits/stdc++.h"
using namespace std;

vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> nums; //creation 2d array using vector
        
        nums.push_back(vector<int> {1}); //pushing 1 to first position
        
        for(int i = 1 ; i < numRows ; i++)
        {
           nums.push_back(vector<int>(i+1));//increasing coloumns with increse in row
          
            nums[i][0] = nums[i][i] = 1; //assigning 1 to start and end coloumn in each row
            
            for(int j = 1 ; j < i ; j++)  //iterating for all the coloumns
            {
                //assigning proper values by applying logic.
                nums[i][j] = nums[i-1][j-1] + nums[i-1][j];
                
            }   
        }
        return nums;
        
    }

    int main()
    {
        int numRows;
        cin>>numRows;
        vector<vector<int>> v = generate(numRows);
        cout<<"[";
        for(auto i : v)
        {
            cout<<"[";
            for(auto j : i)
            {
                cout<<j<<",";
            }
            cout<<"],";
        }

        cout<<"]";

        return 0;
    }