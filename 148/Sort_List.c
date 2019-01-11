/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* quickSort
void swap(struct ListNode *a, struct ListNode *b) {
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}

void quickSort(struct ListNode *head, struct ListNode *end) {
    if (head == end || head->next == end) return;
    struct ListNode *s = head, *f = head->next;
    while (f != end) {
        if (f->val <= head->val) {
            s = s->next;
            swap(s, f);
        }
        f = f->next;
    }
    swap(head, s);
    quickSort(head, s);
    quickSort(s->next, end);
    return;
}

struct ListNode* sortList(struct ListNode* head) {
    quickSort(head, NULL);
    return head;
}
*/

//merge
struct ListNode* mergeTwoSortedLists(struct ListNode *left, struct ListNode *right) {
    struct ListNode dummy;
    struct ListNode *p = &dummy;

    while (left && right) {
        if (left->val < right->val) {
            p->next = left;
            left = left->next;
        } else {
            p->next = right;
            right = right->next;
        }
        p = p->next;
    }

    if (left) p->next = left;
    if (right) p->next = right;
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode *s = head, *f = head;
    struct ListNode *left, *right;
    while (f->next && f->next->next) {
        s = s->next;
        f = f->next->next;
    }

    right = sortList(s->next);
    s->next = NULL;
    left = sortList(head);
    return mergeTwoSortedLists(left, right);
}
