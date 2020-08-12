/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node * copyRandomList(Node * head) {
        if (!head)
            return nullptr;
        unordered_map<Node *, Node *> mp;
        Node * tmp = head;
        Node * new_head = new Node(tmp->val);
        Node * new_tmp = new_head;
        mp[head] = new_head;
        while (tmp) {
            if (tmp->next)
                new_tmp->next = new Node(tmp->next->val);
            else
                new_tmp->next = nullptr;
            new_tmp = new_tmp->next;
            tmp = tmp->next;
            mp[tmp] = new_tmp;
        }
        new_tmp = new_head;
        tmp = head;
        while (new_tmp) {
            new_tmp->random = mp[tmp->random];
            new_tmp = new_tmp->next;
            tmp = tmp->next;
        }
        return new_head;
    }
};
// @lc code=end
