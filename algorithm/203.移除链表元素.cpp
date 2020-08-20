/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    void remove(ListNode * pre, int val) {
        if (!pre || !pre->next)
            return;
        while (pre->next && pre->next->val == val) {
            pre->next = pre->next->next;
        }
        remove(pre->next, val);
    }
    ListNode * removeElements(ListNode * head, int val) {
        ListNode * pre = new ListNode(0);
        pre->next = head;
        remove(pre, val);
        return pre->next;
    }
};
// @lc code=end
