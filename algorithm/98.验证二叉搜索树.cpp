/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    vector<int> ans;
    void inorder(TreeNode * root) {
        if (!root)
            return;
        if (root->left)
            inorder(root->left);
        ans.push_back(root->val);
        if (root->right)
            inorder(root->right);
    }
    bool isValidBST(TreeNode * root) {
        if (!root)
            return true;
        ans.clear();
        inorder(root);
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] >= ans[i + 1])
                return false;
        }
        return true;
    }
};
// @lc code=end
