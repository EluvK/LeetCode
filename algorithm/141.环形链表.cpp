/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
class Solution {
public:
    const int magic_val = 62442;
    bool hasCycle(ListNode * head) {
        while (head) {
            if (head->val == magic_val)
                return true;
            head->val = magic_val;
            head = head->next;
        }
        return false;
    }
};
// @lc code=end
