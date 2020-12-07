/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> ans;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode * f = st.top();
            st.pop();
            if (!f)
                continue;
            ans.push_back(f->val);
            st.push(f->right);
            st.push(f->left);
        }
        return ans;
    }
};
// @lc code=end
