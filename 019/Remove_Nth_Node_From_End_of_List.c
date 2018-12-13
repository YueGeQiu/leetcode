/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy, *p, *q;
    dummy.next = head;
    p = q = &dummy;

    while (n > 0 && q->next) {
        q = q->next;
        n--;
    }

    if (n > 0) return dummy.next;

    while(q->next) {
        p = p->next;
        q = q->next;
    }

    p->next = p->next->next;
    return dummy.next;
}
