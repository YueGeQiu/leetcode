/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/** Recursive
 * struct ListNode* reverseList(struct ListNode* head) {
 *     if (head == NULL || head->next == NULL) return head;
 * 
 *     struct ListNode *cur = reverseList(head->next);
 *     head->next->next = head;
 *     head->next = NULL;
 *     return cur;
 * }
 */

// Iterative
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *cur = head, *pre = NULL, *tmp = NULL;
    while(cur) {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}
