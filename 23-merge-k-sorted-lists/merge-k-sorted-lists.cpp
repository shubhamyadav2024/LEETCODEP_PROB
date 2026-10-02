
class Solution {
public:
ListNode* merge(ListNode* a, ListNode* b){
    ListNode*c =new ListNode(10);
    ListNode* tempC =c;
    while (a!=NULL && b != NULL){
        if(a->val <= b->val){
            tempC->next=a;
            a= a->next;
            tempC = tempC->next;
        }
        else{
            tempC->next=b;
            b= b->next;
            tempC = tempC->next;
        }
    }
    if(a ==NULL) tempC->next= b;
    else tempC->next = a;
    return c-> next;
     
}
    ListNode* mergeKLists(vector<ListNode*>& arr) {
      if(arr.size()==0) return NULL;
      while(arr.size()>1){
        ListNode* a= arr[arr.size()-1];
        arr.pop_back();
        ListNode* b= arr[arr.size()-1];
        arr.pop_back();
        ListNode* c= merge(a,b);
        arr.push_back(c);
      }  
      return arr[0];
    }
};