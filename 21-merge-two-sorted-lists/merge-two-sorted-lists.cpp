
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
       ListNode* c = new ListNode(10);
       ListNode* tempC = c;
       while( a!=NULL && b!=NULL){
        if(a->val <=b->val){
            tempC->next=a;
            a= a->next;
            tempC= tempC->next;
        }
        else{
            tempC->next=b;
            b=b->next;
            tempC= tempC->next;
        }
       } 
       if(a==NULL) tempC->next=b;
       else tempC->next=a;
       return c->next; 
    }
};