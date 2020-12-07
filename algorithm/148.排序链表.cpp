/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode * sortList(ListNode * head) {
        vector<int> arr;
        ListNode * tmp = head;
        while (tmp) {
            arr.push_back(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        sort(arr.begin(), arr.end());
        int index = 0;
        while (tmp) {
            tmp->val = arr[index++];
            tmp = tmp->next;
        }
        return head;
    }
};
// @lc code=end
