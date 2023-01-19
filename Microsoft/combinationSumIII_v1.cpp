#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<vector<int>, int> mp;
    void helper(int &n, int &k, vector<int> presentVector, int presentSum, int currentNum, vector<vector<int>> &ans)
    {
        if (presentVector.size() == k && presentSum == n)
        {
            if (mp[presentVector] == 0)
                ans.push_back(presentVector), mp[presentVector]++;
            return;
        }
        if (currentNum > 9 || presentSum > n)
            return;
        else if (presentSum + currentNum <= n)
        {
            presentVector.push_back(currentNum);
            helper(n, k, presentVector, presentSum + currentNum, currentNum + 1, ans);
            presentVector.pop_back();
        }
        for (int i = 1; i <= 9; i++)
        {
            helper(n, k, presentVector, presentSum, currentNum + i, ans);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> pres;
        helper(n, k, pres, 0, 1, ans);
        return ans;
    }
};