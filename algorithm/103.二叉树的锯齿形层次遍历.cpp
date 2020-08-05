/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        vector<int> tmp;
        int level = 0;
        bool flag = false;
        queue<pair<TreeNode *, int>> q;

        q.push({root, 0});
        while (!q.empty()) {
            pair<TreeNode *, int> f = q.front();
            q.pop();
            if (f.second > level) {
                if (flag)
                    reverse(tmp.begin(), tmp.end());
                ans.push_back(tmp);
                tmp.clear();
                level++;
                flag = flag ? false : true;
            }
            tmp.push_back(f.first->val);
            if (f.first->left)
                q.push(make_pair(f.first->left, f.second + 1));
            if (f.first->right)
                q.push(make_pair(f.first->right, f.second + 1));
        }
        if (!tmp.empty()) {
            if (flag)
                reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
        }
        return ans;
    }
};
// @lc code=end
