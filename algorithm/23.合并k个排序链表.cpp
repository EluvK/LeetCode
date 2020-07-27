/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode * mergeKLists(vector<ListNode *> & lists) {
        int len = lists.size();
        if (len == 0)
            return NULL;
        if (len == 1)
            return lists[0];
        while (len > 1) {
            for (int i = 0; i < len / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            if (len % 2)
                len = len / 2 + 1;
            else
                len = len / 2;
        }
        return lists[0];
    }
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
