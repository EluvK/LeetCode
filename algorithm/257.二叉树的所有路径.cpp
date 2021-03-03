/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> res;
    void dfs(TreeNode * root, std::string str) {
        if (root == nullptr)
            return;
        str = str + "->" + to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(str);
            return;
        }
        dfs(root->left, str);
        dfs(root->right, str);
    }
    vector<string> binaryTreePaths(TreeNode * root) {
        res.clear();
        if (root == nullptr)
            return res;
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(to_string(root->val));
            return res;
        }
        std::string s = to_string(root->val);
        dfs(root->left, s);
        dfs(root->right, s);
        return res;
    }
};
// @lc code=end
