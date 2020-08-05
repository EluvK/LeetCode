/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode *> solve(int l, int r) {
        vector<TreeNode *> ans;
        if (l > r) {
            ans.push_back(nullptr);
            return ans;
        }
        for (int i = l; i <= r; ++i) {
            vector<TreeNode *> left_res = solve(l, i - 1);
            vector<TreeNode *> right_res = solve(i + 1, r);
            for (auto & ln : left_res) {
                for (auto & rn : right_res) {
                    auto t = new TreeNode(i);
                    t->left = ln;
                    t->right = rn;
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }

    vector<TreeNode *> generateTrees(int n) {
        if (!n)
            return vector<TreeNode *>{};
        else
            return solve(1, n);
    }
};
// @lc code=end
