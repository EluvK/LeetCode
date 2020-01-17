class Solution {
public:
    vector<int> res;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        res.clear();
        dfs(root1);
        dfs(root2);
        sort(res.begin(),res.end());
        return res;
    }
    void dfs(TreeNode* root){
        if(root==NULL) return;
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
        return;
    }
};
