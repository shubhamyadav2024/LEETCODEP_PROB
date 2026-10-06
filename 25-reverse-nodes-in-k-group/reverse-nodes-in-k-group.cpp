
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
       ListNode* curr= head;
       ListNode* next=NULL;
       ListNode* pre=NULL;
       

       
       ListNode* temp= head;
       for(int i=0;i<k;i++){
        if(temp==NULL ) return head;
        temp=temp->next;
       } 
       for(int i=0;i<k;i++){
       next = curr->next;
       curr->next=pre;
       pre = curr;
       curr= next;
       }
       head->next=reverseKGroup(curr,k);
       
       return pre;
    }
};