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
    vector<string> v;
    void dfs(TreeNode* root,string str){
        if(!root) return;
        string temp=str+(char)('0'+root->val);
        if(!root->left&&!root->right) v.push_back(temp);
        if(root->left) dfs(root->left,temp);
        if(root->right) dfs(root->right,temp);
    }
    int sumNumbers(TreeNode* root) {
        v.clear();
        dfs(root,"");
        int ans=0;
        for(int i=0;i<v.size();++i){
            ans+=stoi(v[i]);
        }
        return ans;
    }
};
