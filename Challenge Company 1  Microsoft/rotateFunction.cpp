#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int ans = 0, total = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            ans += i * nums[i];
            total += nums[i];
        }
        int temp = ans;
        for (int i = 0; i < n; i++)
        {
            temp += total - n * nums[n - 1 - i];
            ans = max(ans, temp);
        }
        return ans;
    }
};