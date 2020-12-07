/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void inOrder(TreeNode * root) {
        if (!root)
            return;
        inOrder(root->left);
        ans.push_back(root->val);
        inOrder(root->right);
    }
    // vector<int> inorderTraversal(TreeNode * root) {
    //     inOrder(root);
    //     return ans;
    // }
    vector<int> inorderTraversal(TreeNode * root) {
        stack<TreeNode *> st;
        while (!st.empty() || root) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};
// @lc code=end
