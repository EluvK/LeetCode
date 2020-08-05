/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    TreeNode *t1, *t2, *pre;

    void recoverTree(TreeNode * root) {
        inorder(root);
        swap(t1->val, t2->val);
    }

    void inorder(TreeNode * root) {
        if (!root)
            return;
        inorder(root->left);
        if (pre && pre->val > root->val) {
            if (!t1)
                t1 = pre;
            t2 = root;
        }
        pre = root;
        inorder(root->right);
    }
};
// @lc code=end
