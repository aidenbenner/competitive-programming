# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        last = None

        while head is not None:
            tmp = head.next
            head.next = last
            last = head
            head = tmp

        return last

