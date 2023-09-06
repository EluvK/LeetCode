/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode * lcaDeepestLeaves(TreeNode * root) {
        int h;
        return dfs(root, h);
    }
    TreeNode * dfs(TreeNode * root, int & h) {
        if (!root) {
            h = -1;
            return root;
        };
        int r = 0, l = 0;
        auto ln = dfs(root->left, l);
        auto rn = dfs(root->right, r);
        h = max(r, l) + 1;
        if (l == r) {
            return root;
        } else if (l > r) {
            return ln;
        }
        return rn;
    }
};
// @lc code=end
