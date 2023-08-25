/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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
    int ans{0};
    void next(TreeNode * root, int cur_max) {
        if (root->val >= cur_max) {
            ans++;
            cur_max = root->val;
        }
        if (root->left)
            next(root->left, cur_max);
        if (root->right)
            next(root->right, cur_max);
    }
    int goodNodes(TreeNode * root) {
        next(root, root->val);
        return ans;
    }
};
// @lc code=end
