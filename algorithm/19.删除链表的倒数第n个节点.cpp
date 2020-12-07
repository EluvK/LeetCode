/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
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
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        ListNode * pre = new ListNode(NULL);
        pre->next = head;
        ListNode *p = pre, *q = pre;
        while (n--) {
            p = p->next;
        }
        while (p->next) {
            p = p->next;
            q = q->next;
        }
        ListNode * nxt = q->next->next;
        q->next = nxt;
        return pre->next;
    }
};
// @lc code=end
