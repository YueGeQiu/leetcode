/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return NULL;

    struct ListNode dummy;
    struct ListNode *p = &dummy, *q = head;

    p->next = q;

    while (q) {
        while (q->next && q->val == q->next->val) q = q->next;
        if (p->next != q) p->next = q->next;
        else p = q;
        q = p->next;
    }
    return dummy.next;
}
