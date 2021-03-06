/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode * root) {
        if (!root)
            return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        return (l && r) ? 1 + min(r, l) : 1 + l + r;
    }
};
// @lc code=end
