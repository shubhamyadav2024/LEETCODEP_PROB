class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {

            // Duplicate found
            if (curr->next != NULL &&
                curr->val == curr->next->val) {

                int value = curr->val;

                // Skip all nodes having same value
                while (curr != NULL && curr->val == value) {
                    curr = curr->next;
                }

                prev->next = curr;
            }
            else {
                // No duplicate
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};