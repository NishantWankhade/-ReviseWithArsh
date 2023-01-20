#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        queue<TreeNode *> q;
        if (root1 != NULL)
            q.push(root1);
        vector<int> ans;

        while (!q.empty())
        {
            TreeNode *front = q.front();
            ans.push_back(front->val);
            q.pop();
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }

        if (root2 != NULL)
            q.push(root2);
        while (!q.empty())
        {
            TreeNode *front = q.front();
            ans.push_back(front->val);
            q.pop();
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};