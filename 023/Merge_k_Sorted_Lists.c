/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// #define MAX_INT ((unsigned)(-1)>>1)
// #define MIN_INT (~MAX_INT)

// struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
//     struct ListNode dummy, *p;
//     int i, index, min;

//     dummy.next = NULL;
//     p = &dummy;

//     while (1) {
//         index = -1;
//         min = MAX_INT;

//         for (i = 0; i < listsSize; i++) {
//             if (lists[i] && lists[i]->val < min) {
//                 min = lists[i]->val;
//                 index = i;
//             }
//         }

//         if (index == -1) break;

//         p->next = lists[index];
//         p = p->next;
//         lists[index] = lists[index]->next;
//     }

//     return dummy.next;
// }

// DivideConquer
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode *p = &dummy;

    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }

    if (l1) p->next = l1;
    if (l2) p->next = l2;

    return dummy.next;
}

struct ListNode* merge(struct linked** lists, int start, int end) {
    if (start > end) return NULL;
    if (start == end) return lists[start];

    int mid = start + (end - start) / 2;

    return mergeTwoLists(merge(lists, start, mid), merge(lists, mid + 1, end));
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (!lists || listsSize == 0) return NULL;
    return merge(lists, 0, listsSize - 1);
}
