/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int len = 0, i;
    struct ListNode *p = head;
    struct ListNode *cur = head;
    struct ListNode *pre = NULL;
    struct ListNode *next = NULL;

    while (p) {
        len++;
        p = p->next;
    }

    for (i = 0; i < len / 2; i++) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    if (len % 2) cur = cur->next;

    while(pre && cur) {
        if (pre->val != cur->val) return false;
        pre = pre->next;
        cur = cur->next;
    }

    return true;
}
