/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode * sortedListToBST(ListNode * head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums);
    }

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
