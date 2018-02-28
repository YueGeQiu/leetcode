# -*- coding: utf-8 -*-

"""
Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:

    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head

        # start position
        prev = dummy
        current = head

        while current and current.next:
            dup = False

            while current.val == current.next.val:
                current.next = current.next.next
                dup = True

            if dup:
                prev.next = prev.next.next
            else:
                prev = prev.next

            # move forward
            current = current.next
        return dummy.next
