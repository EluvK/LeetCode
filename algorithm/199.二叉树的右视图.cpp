/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode * root) {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            res.push_back(q.front()->val);
            while (sz--) {
                auto f = q.front();
                q.pop();
                if (f->right)
                    q.push(f->right);
                if (f->left)
                    q.push(f->left);
            }
        }
        return res;
    }
};
// @lc code=end
