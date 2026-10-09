class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Step 1: Reverse both lists
        ListNode* pre1 = reverseList(l1);
        ListNode* pre2 = reverseList(l2);

        // Step 2: Add the digits
        ListNode* dummy = new ListNode(0);
        ListNode* d = dummy;

        int carry = 0;

        while (pre1 != NULL || pre2 != NULL || carry != 0) {
            int sum = carry;

            if (pre1 != NULL) {
                sum += pre1->val;
                pre1 = pre1->next;
            }

            if (pre2 != NULL) {
                sum += pre2->val;
                pre2 = pre2->next;
            }

            carry = sum / 10;

            d->next = new ListNode(sum % 10);
            d = d->next;
        }

        // Step 3: Reverse the result
        ListNode* ans = reverseList(dummy->next);

        // Step 4: Restore the original lists
        reverseList(l1);
        reverseList(l2);

        return ans;
    }
};