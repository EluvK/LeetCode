/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode * head) {
        ListNode * first = new ListNode(0);
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            auto tmp = slow->next;
            slow->next = first->next;
            first->next = slow;
            slow = tmp;
        }
        if (fast != nullptr) {
            slow = slow->next;
        }
        while (slow != nullptr) {
            if (slow->val != first->next->val) {
                return false;
            }
            slow = slow->next;
            first = first->next;
        }

        return true;
    }
};
// @lc code=end
