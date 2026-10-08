
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
           if (head == NULL || head->next == NULL)
            return NULL;

        ListNode* temp = head;
        int n=0;
        while(temp){
            temp=temp->next;
            n++;
        }
        int size =n/2;
        temp=head;
        for(int i=1;i<size;i++){
         temp=temp->next;

        }
        temp->next=temp->next->next;
        return head;
    }
};