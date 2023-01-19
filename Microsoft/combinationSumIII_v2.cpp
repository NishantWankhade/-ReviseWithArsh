#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    void helper(int k, int sum, vector<int> currVector, int present, int currSum)
    {
        if (currVector.size() == k && sum == currSum)
        {
            ans.push_back(currVector);
            return;
        }
        else if (currVector.size() > k || sum < currSum)
        {
            return;
        }
        for (int i = present + 1; i <= 9; i++)
        {
            currVector.push_back(i);
            if (currSum + i > sum)
                break;
            helper(k, sum, currVector, i, currSum + i);
            currVector.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        helper(k, n, {}, 0, 0);
        return ans;
    }
};