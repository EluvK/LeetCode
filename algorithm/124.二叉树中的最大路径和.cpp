/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode * root, int & res) {
        if (!root)
            return 0;
        int left = max(0, solve(root->left, res));
        int right = max(0, solve(root->right, res));
        res = max(res, root->val + left + right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode * root) {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};
// @lc code=end
