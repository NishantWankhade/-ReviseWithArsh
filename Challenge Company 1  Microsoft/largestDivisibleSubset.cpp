#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        if (n == 0)
            return ans;

        int maxLen = 1;
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 and dp[j] == dp[i])
                {
                    dp[i] = 1 + dp[j];
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }

        int prev = -1;

        for (int i = n - 1; i >= 0; i--)
        {

            if (prev == -1 and dp[i] == maxLen)
            {
                prev = nums[i];
                ans.push_back(nums[i]);
                maxLen--;
            }

            else if (prev % nums[i] == 0 and maxLen == dp[i])
            {
                maxLen--;
                ans.push_back(nums[i]);
                prev = nums[i];
            }
        }

        return ans;
    }
};