/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode * root) { return ismirror(root, root); }

    bool ismirror(TreeNode * p, TreeNode * q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        return p->val == q->val && ismirror(p->left, q->right) && ismirror(p->right, q->left);
    }
};
// @lc code=end
