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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cntList=head;
        int cnt=0;
        while(cntList!=NULL&&cnt<k){
            cnt++;cntList=cntList->next;
        }
        if(cnt!=k) return head;

        ListNode *cur=head;
        ListNode *pre=NULL;
        for(int i=0;i<k;i++){
            ListNode *nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        head->next=reverseKGroup(cur,k);
        return pre;
    }
};
