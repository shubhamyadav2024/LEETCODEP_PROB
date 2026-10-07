class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return NULL;

        // Step 1: Create duplicate list
        Node* c = new Node(10);
        Node* tempc = c;
        Node* temp = head;

        while (temp) {
            Node* a = new Node(temp->val);
            tempc->next = a;
            tempc = tempc->next;
            temp = temp->next;
        }

        // Step 2: Alternate connections
        Node* dup = c->next;
        Node* a = head;
        Node* b = dup;

        c = new Node(-1);
        Node* tem = c;

        while (a) {

            // Original node
            tem->next = a;
            tem = tem->next;

            a = a->next;
            // Duplicate node
            tem->next = b;
            tem = tem->next;

            b = b->next;
        }

        c = c->next;

        // Step 3: Copy random pointers
        Node* t1 = c;

        while (t1) {

            Node* t2 = t1->next;

            if (t1->random != NULL)
                t2->random = t1->random->next;

            t1 = t1->next->next;
        }

        // Step 4: Separate original and copied list
        Node* d1 = new Node(-1);
        Node* d2 = new Node(-1);

        Node* t1_dummy = d1;
        Node* t2_dummy = d2;

        Node* t = c;

        while (t) {

            // Original node
            t1_dummy->next = t;
            t1_dummy = t1_dummy->next;

            // Copy node
            t2_dummy->next = t->next;
            t2_dummy = t2_dummy->next;

            t = t->next->next;
        }

        // End both lists
        t1_dummy->next = NULL;
        t2_dummy->next = NULL;

        return d2->next;
    }
};