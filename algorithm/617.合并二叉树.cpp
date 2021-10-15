/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 */

// @lc code=start
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
    TreeNode * do_merge(TreeNode * root, TreeNode * l, TreeNode * r) {
        if (l != nullptr || r != nullptr) {
            root = new TreeNode();
            if (l != nullptr)
                root->val += l->val;
            if (r != nullptr)
                root->val += r->val;
            // std::cout << root->val << std::endl;
            root->left = do_merge(root->left, l ? l->left : nullptr, r ? r->left : nullptr);
            root->right = do_merge(root->right, l ? l->right : nullptr, r ? r->right : nullptr);
            return root;
        }
        return nullptr;
    }
    TreeNode * mergeTrees(TreeNode * root1, TreeNode * root2) {
        TreeNode * root = nullptr;
        return do_merge(root, root1, root2);
    }
};
// @lc code=end
