#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        map<char, int> mp;
        map<int, int> bullPos;
        for (auto x : secret)
        {
            mp[x]++;
        }

        int bulls = 0, cows = 0;

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
                mp[secret[i]]--;
                bullPos[i]++;
            }
        }

        for (int i = 0; i < secret.size(); i++)
        {
            char x = guess[i];
            if (bullPos[i] != 0)
                continue;
            if (mp[x] > 0)
                cows++, mp[x]--;
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
