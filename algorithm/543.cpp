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
    int ans=0;
    int getHeight(TreeNode *root){
        if(root){
            int l=getHeight(root->left);
            int r=getHeight(root->right);
            if(l+r>ans) ans=l+r;
            return max(l,r)+1;
        }
        return 0;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root) int tmp=getHeight(root);
        return ans;
    }

};
