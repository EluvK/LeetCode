/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode * create(vector<int> & pre, vector<int> & in, int preL, int preR, int inL, int inR) {
        if (preL > preR || inL > inR)
            return nullptr;
        TreeNode * root = new TreeNode(pre[preL]);

        int k = 0;
        for (k = inL; k <= inR; ++k) {
            if (in[k] == pre[preL])
                break;
        }
        // [preL+1,preL+k-inL] , [preL+k-inL+1,preR]
        // [inL,k-1] , [k+1,inR]

        root->left = create(pre, in, preL + 1, preL + k - inL, inL, k - 1);
        root->right = create(pre, in, preL + k - inL + 1, preR, k + 1, inR);
        return root;
    }
    TreeNode * buildTree(vector<int> & preorder, vector<int> & inorder) {
        TreeNode * root = create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        return root;
    }
};
// @lc code=end
