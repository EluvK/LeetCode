/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node * connect(Node * root) {
        if (root && (root->left || root->right)) {
            if (root->left && root->right)
                root->left->next = root->right;

            Node * node = root->right ? root->right : root->left;
            Node * nxt = root->next;
            while (nxt && !(nxt->left || nxt->right)) {
                nxt = nxt->next;
            }
            node->next = nxt ? (nxt->left ? nxt->left : nxt->right) : nullptr;

            connect(root->right);
            connect(root->left);
        }
        return root;
    }
};
// @lc code=end
