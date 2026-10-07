
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       ListNode* temp=head;
       int n = 0;
       while(temp){
        temp=temp->next;
        n++;
       } 
       vector<ListNode*> ans;
       int size = n/k;
       int rem= n%k;
       temp= head;
       while(temp !=NULL){
        ListNode* c = new ListNode(10);
        ListNode* tempc =c;
        int s=size;
        if(rem>0) s++;
        rem--;
        for(int i =1;i<=s;i++){
            tempc->next= temp;
            temp=temp->next;
            tempc=tempc->next;
        }
        tempc->next = NULL;
        ans.push_back(c->next);
       }
       if(ans.size()<k){
       int extra = k-ans.size();
       for(int i =1;i<=extra;i++){
        ans.push_back(NULL);
       }
       }
       return ans;
    }
};