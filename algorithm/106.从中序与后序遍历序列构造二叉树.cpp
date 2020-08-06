/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode * create(vector<int> & in, vector<int> & post, int inL, int inR, int postL, int postR) {
        if (postL > postR || inL > inR)
            return nullptr;
        TreeNode * root = new TreeNode(post[postR]);

        int k = 0;
        for (k = inL; k <= inR; ++k) {
            if (in[k] == post[postR])
                break;
        }
        // [preL+1,preL+k-inL] , [preL+k-inL+1,preR]
        // [inL,k-1] , [k+1,inR]
        // [postL,postL+k-1-inL] , [postL+k-inL,postR-1]

        root->left = create(in, post, inL, k - 1, postL, postL + k - 1 - inL);
        root->right = create(in, post, k + 1, inR, postL + k - inL, postR - 1);
        return root;
    }
    TreeNode * buildTree(vector<int> & inorder, vector<int> & postorder) {
        TreeNode * root = create(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
        return root;
    }
};
// @lc code=end
