/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(TreeNode * root, int _sum, int target) {
        tmp.push_back(root->val);
        _sum += root->val;
        if (!root->left && !root->right && _sum == target) {
            ans.push_back(tmp);
        } else {
            if (root->left)
                dfs(root->left, _sum, target);
            if (root->right)
                dfs(root->right, _sum, target);
        }
        _sum -= root->val;
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode * root, int sum) {
        if (!root)
            return ans;
        dfs(root, 0, sum);
        return ans;
    }
};
// @lc code=end
