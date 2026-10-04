
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL )return head;
     ListNode* c = new ListNode();
     ListNode* temp =head;
     ListNode* tempc= c;
     while(temp!=NULL && temp->next != NULL){
        tempc->next = temp->next;
        temp->next= tempc->next->next;
        tempc->next->next= temp;
        tempc=temp;
        temp=temp->next;
     }  
     return c->next; 
    }
};