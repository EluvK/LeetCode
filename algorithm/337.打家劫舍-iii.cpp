/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
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
    using pii = pair<int, int>;
    pii dfs(TreeNode * root) {
        if (!root)
            return make_pair(0, 0);
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        return make_pair(root->val + left.second + right.second, max(left.first, left.second) + max(right.first, right.second));
    }
    int rob(TreeNode * root) {
        auto r = dfs(root);
        return max(r.first, r.second);
    }
};
// @lc code=end
