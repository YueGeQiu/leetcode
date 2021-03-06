# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # recursive
        # if not head or not head.next:
        #     return head
        # cur = self.reverseList(head.next)
        # head.next.next = head
        # head.next = None
        # return cur
        
        # iterative
        pre, cur = None, head
        while cur:
            nextNode = cur.next
            cur.next = pre
            pre = cur
            cur = nextNode
        return pre
