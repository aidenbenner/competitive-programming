# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if head is None: return None

        lag = n + 1
        hare  = head
        for x in range(lag):
            if hare is None:
                return head.next
            hare = hare.next
        turtle = head

        while hare is not None:
            hare = hare.next
            turtle = turtle.next

        turtle.next = turtle.next.next

        return head

