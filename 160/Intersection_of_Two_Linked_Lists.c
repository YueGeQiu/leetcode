/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
    struct ListNode *p = headA, *q = headB;
    while (p != q) {
        p = p == NULL ? headB : p->next;
        q = q == NULL ? headA : q->next;
    }
    return p;
}
