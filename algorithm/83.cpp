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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head){
            ListNode *nxt=head->next;
            while(nxt&&head->val==nxt->val) nxt=nxt->next;
            head->next=deleteDuplicates(nxt);
        }
        return head;
    }
};
