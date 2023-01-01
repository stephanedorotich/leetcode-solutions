// Author: Stéphane Dorotich
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * start;
        ListNode * curr;
        bool carry = false;
        int sum;

        sum = l1->val + l2->val;
        if (sum >= 10) {
            carry = true;
            start = new ListNode(sum - 10);
        } else start = new ListNode(sum);
        
        curr = start;

        l1 = l1->next;
        l2 = l2->next;

        while (l1 != nullptr && l2 != nullptr) {
            // Determine sum
            sum = l1->val + l2->val;
            if (carry) sum++;

            // Create new node
            if (sum < 10) {
                carry = false;
                curr->next = new ListNode(sum);
            } else {
                carry = true;
                curr->next = new ListNode(sum-10);
            }

            // Update pointers
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        // Check if one list has more numbers to process
        if (l1 != nullptr || l2 != nullptr) {
            ListNode * remaining;
            // Pick list with remaining
            if (l1 != nullptr) remaining = l1;
            else remaining = l2;

            if (carry) {
                while (remaining != nullptr) {
                    sum = remaining->val + 1;
                    if (sum == 10) {
                        curr->next = new ListNode();
                        curr = curr->next;
                        remaining = remaining->next;
                        continue;
                    } else {
                        carry = false;
                        curr->next = new ListNode(sum);
                        curr = curr->next;
                        remaining = remaining->next;
                        break;
                    }
                }
            }
            while (remaining != nullptr) {
                curr->next = new ListNode(remaining->val);
                curr = curr->next;
                remaining = remaining->next;
            }
        }
        if (carry) curr->next = new ListNode(1);
        return start;
    }
};
