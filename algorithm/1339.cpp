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
    long long ans=0;
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        root->val+=dfs(root->left)+dfs(root->right);
        return root->val;
    }
    void rdfs(TreeNode* root,int sum){
        if(root->left){
            long long temp=(long long)(sum-root->left->val)*(long long)(root->left->val);
            if(temp>ans) ans=temp;
            rdfs(root->left,sum);
        }
        if(root->right){
            long long temp=(long long)(sum-root->right->val)*(long long)(root->right->val);
            if(temp>ans) ans=temp;
            rdfs(root->right,sum);
        }
    }
    int maxProduct(TreeNode* root) {
        root->val=dfs(root);
        int sum=root->val;
        rdfs(root,sum);

        return ans%1000000007;
    }
};
