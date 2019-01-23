/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode ret;
    struct ListNode *p = &ret;
    int carry = 0, sum;

    ret.next = NULL;

    while (l1 || l2 || carry != 0) {
        sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        p->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        p = p->next;
        p->val = sum % 10;
        carry = sum / 10;
    }

    return ret.next;
}
