/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
    vector<int> arr;
    int index{0};
    BSTIterator(TreeNode * root) {
        dfs(root);
        sort(arr.begin(), arr.end());
    }

    void dfs(TreeNode * root) {
        if (!root)
            return;
        arr.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

    /** @return the next smallest number */
    int next() { return arr[index++]; }

    /** @return whether we have a next smallest number */
    bool hasNext() { return index != arr.size(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
