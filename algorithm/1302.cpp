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
    int sum[50]={0};
    int book[50]={0};
    void dfs(TreeNode * root,int l){
        sum[l]+=root->val;
        book[l]=1;
        if(root->left!=NULL) dfs(root->left,l+1);
        if(root->right!=NULL) dfs(root->right,l+1);
        return;
    }

    int deepestLeavesSum(TreeNode* root) {

        dfs(root,0);

        for(int i=49;i--;i>=0){
            if(book[i]!=0) return sum[i];
        }
        return 0;
    }
};
