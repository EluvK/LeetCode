/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q) {
        return (root == p || root == q) ? root :
                                          (((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val)) ?
                                               root :
                                               (root->val > p->val ? lowestCommonAncestor(root->left, p, q) : lowestCommonAncestor(root->right, p, q)));
    }
};
// @lc code=end
