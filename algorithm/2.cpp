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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0),*p=&head;
        int flag=0;
        while(l1||l2||flag){
            int temp=0;
            if(l1!=NULL) temp+=l1->val;
            if(l2!=NULL) temp+=l2->val;
            temp+=flag;
            flag=temp/10;
            temp%=10;

            ListNode *next=l1?l1:l2;
            if(next==NULL) next=new ListNode(temp);
            next->val=temp;
            p->next=next;
            p=p->next;
            l1=l1?l1->next:NULL;
            l2=l2?l2->next:NULL;
        }
        return head.next;
    }
};
