/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode * ans = new ListNode(0);
        ListNode * cur = ans;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val > l2->val) {
                cur->next = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        cur->next = l1 == NULL ? l2 : l1;
        return ans->next;
    }
};
// @lc code=end
