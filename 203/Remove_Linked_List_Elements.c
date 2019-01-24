/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy, *p;
    p = &dummy;
    p->next = head;
    while (p->next) {
        if (p->next->val == val) p->next = p->next->next;
        else p = p->next;
    }

    return dummy.next;
}
