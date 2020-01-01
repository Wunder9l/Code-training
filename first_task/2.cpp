/**
 // https://leetcode.com/problems/add-two-numbers/
 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n;
        int additional = 0;
        ListNode start(0);
        auto cur = &start;
        while (l1 || l2) {
            n = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + additional;
            additional = n / 10;
            cur->next = new ListNode(n%10);
            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if (additional) {
            cur->next = new ListNode(additional);
        }
        return start.next;
    }
};
