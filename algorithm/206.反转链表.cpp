/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode * reverseList(ListNode * head) {
        ListNode * pre = nullptr;
        for (; head; swap(head->next, pre), swap(head, pre))
            ;
        return pre;
    }
};
// @lc code=end
