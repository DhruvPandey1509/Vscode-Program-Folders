#include <iostream>
#include "Trie.h"
using namespace std;

int main()
{
    string words[] = {"hello", "he", "apple", "news"};
    Trie t;

    for (auto word : words)
    {
        t.insert(word);
    }

    string key;
    cin >> key;

    cout << t.search(key) << endl;

    string query[] = {"hello", "mango", "apple"};
    for(auto s : query)
    {
        cout<<s<<" : "<<t.search(s)<<endl;
    }

    return 0;
}