/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
#if 0
    int getHeight(TreeNode * root) {
        if (!root)
            return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    TreeNode * l_rotation(TreeNode * root) {
        TreeNode * temp = root->right;
        root->right = temp->left;
        temp->left = root;
        return temp;
    }

    TreeNode * r_rotation(TreeNode * root) {
        TreeNode * temp = root->left;
        root->left = temp->right;
        temp->right = root;
        return temp;
    }

    TreeNode * rl_rotation(TreeNode * root) {
        root->right = r_rotation(root);
        return l_rotation(root);
    }

    TreeNode * lr_rotation(TreeNode * root) {
        root->left = l_rotation(root);
        return r_rotation(root);
    }

    void insert(TreeNode *& root, int n) {
        if (!root)
            root = new TreeNode(n);
        else if (root->val > n) {
            insert(root->left, n);
            int l = getHeight(root->left), r = getHeight(root->right);
            if (l - r >= 2) {
                if (root->left->val > n)
                    root = r_rotation(root);
                else
                    root = lr_rotation(root);
            }
        } else {
            insert(root->right, n);
            int l = getHeight(root->left), r = getHeight(root->right);
            if (r - l >= 2) {
                if (root->right->val < n)
                    root = l_rotation(root);
                else
                    root = rl_rotation(root);
            }
        }
    }

    TreeNode * sortedArrayToBST(vector<int> & nums) {
        TreeNode * root = nullptr;
        for (int i = 0; i < nums.size(); insert(root, nums[i++]))
            ;
        return root;
    }
#endif
    TreeNode * sortedArrayToBST(vector<int> & nums) { return solve(nums, 0, nums.size() - 1); }
    TreeNode * solve(vector<int> & nums, int l, int r) {
        if (r < l)
            return nullptr;
        int mid = l + ((r - l) >> 1);

        TreeNode * root = new TreeNode(nums[mid]);
        root->left = solve(nums, l, mid - 1);
        root->right = solve(nums, mid + 1, r);
        return root;
    }
};
// @lc code=end
