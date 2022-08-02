#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        map<char, int> store;
        int bulls = 0, cows = 0;
        int n1 = secret.size(), n2 = guess.size();

        for (int i = 0; i < n1; i++)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            else
                store[secret[i]]++;
        }

        for (int i = 0; i < n2; i++)
        {
            if (store[guess[i]] > 0 and guess[i] != secret[i])
            {
                cows++;
                store[guess[i]]--;
            }
        }

        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};