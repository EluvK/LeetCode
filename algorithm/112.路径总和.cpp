/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start
using namespace std;
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
    bool hasPathSum(TreeNode * root, int sum) {
        return root && ((!root->left && !root->right && root->val == sum) || hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    }
};
// @lc code=end
