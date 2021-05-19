/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode * root) {
        if (root == NULL)
            return "#_";
        string res = to_string(root->val) + "_";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode * deserialize(string data) {
        std::stringstream ss(data);
        std::string item;
        queue<string> q;
        while (std::getline(ss, item, '_'))
            q.push(item);
        return helper(q);
    }
    TreeNode * helper(queue<string> & q) {
        string val = q.front();
        q.pop();
        if (val == "#")
            return NULL;
        TreeNode * head = new TreeNode(stoi(val));
        head->left = helper(q);
        head->right = helper(q);
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
