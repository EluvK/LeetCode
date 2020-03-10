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
    struct Mp {
        bool isBST;
        int sum;
    };
    int res=0;

    Mp dfs(TreeNode *root) {
        if(root==NULL) return{false,0};

        int sum=root->val;
        Mp l=dfs(root->left);
        Mp r=dfs(root->right);
        sum+=l.sum;
        sum+=r.sum;

        if ((root->left&&!l.isBST)||(root->right&&!r.isBST))
            return {false,0};
        if (root->left&&root->left->val>=root->val)
            return {false,root->val};
        if (root->right&&root->right->val<=root->val)
            return {false,root->val};

        res=max(res,sum);
        return {true,sum};
    }
    int maxSumBST(TreeNode* root) {
        if(!root) return res;
        dfs(root);
        return res;
    }
};
