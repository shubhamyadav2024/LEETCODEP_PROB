class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return {-1, -1};

        ListNode* pre = head;
        ListNode* curr = head->next;
        ListNode* temp = head->next->next;

        int idx = 1;

        int first = -1;       // first critical point
        int prev = -1;        // previous critical point

        int minDist = INT_MAX;
        int maxDist = -1;

        while (temp != NULL) {

            // Check whether curr is a critical point
            bool critical =
                (curr->val > pre->val && curr->val > temp->val) ||
                (curr->val < pre->val && curr->val < temp->val);

            if (critical) {

                // First critical point
                if (first == -1) {
                    first = idx;
                }

                // From second critical point onward
                if (prev != -1) {
                    int dist = idx - prev;
                    minDist = min(minDist, dist);

                    // Distance from first to current
                    maxDist = idx - first;
                }

                prev = idx;
            }

            pre = curr;
            curr = temp;
            temp = temp->next;

            idx++;
        }

        if (maxDist == -1)
            return {-1, -1};

        return {minDist, maxDist};
    }
};