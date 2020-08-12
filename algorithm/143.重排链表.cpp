/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

// @lc code=start
using namespace std;
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
    void reorderList(ListNode * head) {
        if (!head || !head->next || !head->next->next)
            return;
        ListNode *mid = head, *tmp = head, *mid_pre;
        while (tmp && tmp->next) {
            tmp = tmp->next->next;
            mid_pre = mid;
            mid = mid->next;
        }
        mid_pre->next = nullptr;
        ListNode * mid_head = nullptr;
        for (; mid; swap(mid->next, mid_head), swap(mid, mid_head))
            ;
        tmp = head;
        while (tmp && mid_head) {
            mid_pre = tmp;
            ListNode * nxt = tmp->next;
            tmp->next = mid_head;
            mid_head = mid_head->next;
            tmp->next->next = nxt;
            tmp = nxt;
        }
        tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = mid_head;
    }
};
// @lc code=end
