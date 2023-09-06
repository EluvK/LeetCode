/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
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
        if (!root)
            return "";
        if (!root->left && !root->right)
            return to_string(root->val);
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    void insert(TreeNode *& root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return;
        }
        if (root->val > val)
            insert(root->left, val);
        else
            insert(root->right, val);
    }

    std::vector<std::string> split(std::string s, std::string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        std::vector<std::string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode * deserialize(string data) {
        vector<string> values = split(data, ",");
        TreeNode * root = nullptr;
        for (auto s : values) {
            if (!s.empty()) {
                insert(root, stoi(s));
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
