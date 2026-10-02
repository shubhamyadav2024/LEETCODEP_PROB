
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     ListNode* slow= head;
     ListNode* fast= head;
     bool flag= false;
     while(fast != NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
     
     if(fast==slow){
        flag =true;
        break;
     }
     }
     if(flag== false) {
        return NULL;
     }
     else{
     ListNode* temp=head;
     while(temp !=slow){
        temp= temp->next;
        slow= slow->next;
     }
     }
return slow;
    }
};