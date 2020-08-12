/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode * detectCycle(ListNode * head) {
        ListNode *p = head, *q = head;

        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                p = head;
                while (p != q) {
                    p = p->next;
                    q = q->next;
                }
                return q;
            }
        }
        return nullptr;
    }
};
// @lc code=end
