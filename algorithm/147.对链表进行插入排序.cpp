/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode * insertionSortList(ListNode * head) {
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
