/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode * rotateRight(ListNode * head, int k) {
        if (head == nullptr)
            return head;
        ListNode * head_ = head;
        int cnt = 1;
        while (head_->next != nullptr) {
            cnt++;
            head_ = head_->next;
        }
        head_->next = head;
        k %= cnt;
        k = cnt - k;
        head_ = head;
        while (--k) {
            head_ = head_->next;
        }
        ListNode * res = head_->next;
        head_->next = nullptr;
        return res;
    }
};
// @lc code=end
