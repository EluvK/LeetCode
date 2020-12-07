/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode * rear = nullptr;
    ListNode * slove(ListNode * head, int m, int n, int index) {
        if (index < m) {
            head->next = slove(head->next, m, n, index + 1);
            return head;
        }
        if (index == n) {
            rear = head->next;
            return head;
        }
        if (index > n) {
            return head;
        }
        if (!head || !head->next)
            return head;
        ListNode * tmp = slove(head->next, m, n, index + 1);
        head->next->next = head;
        head->next = rear;
        return tmp;
    }
    ListNode * reverseBetween(ListNode * head, int m, int n) { return slove(head, m, n, 1); }
};
// @lc code=end
