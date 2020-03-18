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
    vector<int> num;
    void dfs(TreeNode* root){
        if(root==NULL) return;
        dfs(root->left);
        num.push_back(root->val);
        dfs(root->right);
        return;
    }
    TreeNode *dc(int st,int ed){
        if(st>ed) return NULL;
        int ind=(st+ed)/2;
        TreeNode *root=new TreeNode(num[ind]);
        root->left=dc(st,ind-1);
        root->right=dc(ind+1,ed);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        int len=num.size();
        TreeNode *newroot=NULL;
        newroot=dc(0,len-1);
        return newroot;
    }
};
