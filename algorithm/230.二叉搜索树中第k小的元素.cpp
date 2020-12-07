/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

// @lc code=start
using namespace std;
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
    int in(TreeNode * root, int & k) {
        int res;
        if (root->left) {
            res = in(root->left, k);
            if (res != INT_MAX) {
                return res;
            }
        }
        if (!--k)
            return root->val;
        if (root->right) {
            res = in(root->right, k);
            if (res != INT_MAX) {
                return res;
            }
        }
        return INT_MAX;
    }
    int kthSmallest(TreeNode * root, int k) { return in(root, k); }
};
// @lc code=end
