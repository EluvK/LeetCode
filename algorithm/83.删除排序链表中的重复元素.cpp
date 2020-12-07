/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode * deleteDuplicates(ListNode * head) {
        if (head) {
            ListNode * nxt = head->next;
            while (nxt && head->val == nxt->val)
                nxt = nxt->next;
            head->next = deleteDuplicates(nxt);
        }
        return head;
    }
};
// @lc code=end
