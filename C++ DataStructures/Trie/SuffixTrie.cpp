#include<iostream>
#include"SuffixTrie.h"

using namespace std;

int main()
{
    string input = "hello";
    string suffixes[] = {"lo", "ell", "hello"};

    SuffixTrie t;
    t.insert(input);

    for(auto sf : suffixes)
    {
        if(t.search(sf))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }

    return 0;
}