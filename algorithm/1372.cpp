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
    int res=0;
    int longestZigZag(TreeNode* root) {
        res=max(res,dfs(root->left,1,0));
        res=max(res,dfs(root->right,1,1));
        return res;
    }
    // 0 left, 1 right
    int dfs(TreeNode* root,int depth,int dir) {
        if(!root) return 0;
        int cnt=0;
        if (dir==0) {
            res=max(res,dfs(root->left,1,0));
            cnt=dfs(root->right,depth+1,1);
        }else{
            res=max(res,dfs(root->right,1,1));
            cnt=dfs(root->left,depth+1,0);
        }
        return cnt+1;
    }
};
