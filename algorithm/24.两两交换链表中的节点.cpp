/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode * swapPairs(ListNode * head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode * nxt = head->next;
        head->next = swapPairs(nxt->next);
        nxt->next = head;
        return nxt;
    }
};
// @lc code=end
