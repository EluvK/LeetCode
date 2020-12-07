/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode * partition(ListNode * head, int x) {
        ListNode * leftGuard = new ListNode(-1);
        ListNode * rightGuard = new ListNode(-1);
        ListNode * left = leftGuard;
        ListNode * right = rightGuard;
        leftGuard->next = rightGuard;
        while (head != nullptr) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            } else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }
        left->next = rightGuard->next;
        right->next = nullptr;
        return leftGuard->next;
    }
};
// @lc code=end
