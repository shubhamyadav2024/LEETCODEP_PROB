
class Solution {
public:
   ListNode* reverselist(ListNode* head ){
    ListNode* prev= NULL;
   
    ListNode* next= head;
    ListNode* curr= head;
    
    while(curr){
        next= curr->next;
        curr->next=prev;
        prev= curr;
        curr= next;
    }
    return prev;
   }
    bool isPalindrome(ListNode* head) {
       ListNode* c = new ListNode();
       ListNode* tempc =c;
       ListNode* temp=head;
      
       while(temp){
        ListNode* node = new ListNode(temp->val); 
        tempc->next= node;
        temp= temp->next;
        tempc= tempc->next;
       }
       c =c->next;
       c = reverselist(c);
       ListNode* a = head;
       ListNode* b =c;
       while(a){
        if(a->val != b->val) return false;
        a=a->next;
        b=b->next;
       }
       return true;
    }
};