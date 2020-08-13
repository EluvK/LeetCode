/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode * root) {
        vector<int> ans;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode * f = st.top();
            st.pop();
            if (!f)
                continue;
            ans.push_back(f->val);
            st.push(f->left);
            st.push(f->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
