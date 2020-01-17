/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node *temp=head;
        vector<Node *> nxt;
        while(head!=NULL||nxt.size()==0){
            if(nxt.size()!=0){
                Node *nt=nxt.back();
                head->next=nt;
                nt->prev=head;
                head=nt;
            }
            while(head!=NULL&&head->child==NULL)
                head=head->next;
            if(head!=NULL&&head->next!=NULL) nxt.push_back(head->next);
            if(head!=NULL&&head->child!=NULL){
                Node *c=head->child;
                head->child=NULL;
                c->prev=head;
                head->next=c;
                head=c;
            }
        }
        return temp;
    }
};
