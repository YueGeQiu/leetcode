# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        head = current = ListNode(0)
        
        while l1 or l2 or carry > 0:
            # initialization
            a = b = 0
            if l1:
                a = l1.val
                l1 = l1.next
            if l2:
                b = l2.val
                l2 = l2.next
            # add
            sum = a + b + carry
            carry = int(sum / 10) # Python 3 need to cast to integer
            current.next = ListNode(sum % 10)
            # move to next
            current = current.next
        return head.next
        