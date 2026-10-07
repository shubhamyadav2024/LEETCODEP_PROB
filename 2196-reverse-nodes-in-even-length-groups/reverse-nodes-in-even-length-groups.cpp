
class Solution {
public:
 ListNode* reverselist(ListNode* head){
    if(head ==NULL) return head;
    ListNode* pre= NULL;
    ListNode* next= NULL;
    ListNode* curr= head;
    while(curr){
        next= curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    return pre;
  }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* a= NULL;
        ListNode* b= NULL;
        ListNode* c= NULL;
        ListNode* d= NULL;
        ListNode* temp= head;
        int n =1;
        while(temp != NULL){
            if(n==left-1) a =temp;
            if(n==left) b =temp;
            if(n==right) c =temp;
            if(n==right+1) d =temp;
            temp = temp->next;
            n++; 
        }
         if(a) a->next = NULL;
         c->next = NULL;
         c = reverselist(b);
        if(a) a->next = c;
         b->next= d;
         if(a) return head;
         return c;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
      ListNode* temp= head;
      int gap=1;
      while(temp && temp->next){
        ListNode* t = temp->next;
        int rem= 0;
        for(int i=1;i<=gap+1 && t !=NULL;i++){
            t=t->next;
            rem++;
        }
        if(rem<gap+1) gap=rem-1;
        if(gap %2 !=0)reverseBetween(temp,2,gap+2);
        gap++;
        for(int i=1; temp !=NULL && i<=gap;i++){
            temp=temp->next;
        }
      }  
      return head;
    }
};