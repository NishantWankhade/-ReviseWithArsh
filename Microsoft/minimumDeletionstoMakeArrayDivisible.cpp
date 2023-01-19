#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        int result = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); i++)
        {
            result = gcd(result, numsDivide[i]);
        }
        map<int, int> mp;
        for (auto x : nums)
        {
            mp[x]++;
        }
        int ans = 0;
        for (auto x : mp)
        {
            if (result % x.first == 0)
                break;
            else
                ans += x.second;
        }

        if (ans >= nums.size())
            return -1;
        return ans;
    }
};