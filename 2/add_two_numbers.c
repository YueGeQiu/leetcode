/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int tmp = 0;
    struct ListNode *pHead, *p, *pl1, *pl2;
    pHead = NULL;
    if(l1 || l2 || tmp) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        pHead = p;
        p->val = l1 ? l1->val : 0;
        p->val += l2 ? l2->val : 0;
        p->val += tmp;
        tmp = p->val / 10;
        p->val = p->val % 10;
        pl1 = l1 ? l1->next : NULL;
        pl2 = l2 ? l2->next : NULL;
        p->next = NULL;
    }

    while(pl1 || pl2 || tmp) {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        
        p->val = pl1 ? pl1->val : 0;
        p->val += pl2 ? pl2->val : 0;
        p->val += tmp;
        tmp = p->val / 10;
        p->val = p->val % 10;
        pl1 = pl1 ? pl1->next : NULL;
        pl2 = pl2 ? pl2->next : NULL;
        p->next = NULL;
    }
    return pHead;
}