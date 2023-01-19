#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int i = -1;
        int n = nums.size();

        if (n == 1)
            return 0;
        int present = nums[0];

        for (int x = 1; x < n; x++)
        {
            if (nums[x] < present)
            {
                i = x;
            }
            else
            {
                present = nums[x];
            }
        }
        int j = 0;
        int prev = nums[n - 1];

        for (int y = n - 2; y >= 0; y--)
        {
            if (prev < nums[y])
            {
                j = y;
            }
            else
            {
                prev = nums[y];
            }
        }

        return i - j + 1;
    }
};