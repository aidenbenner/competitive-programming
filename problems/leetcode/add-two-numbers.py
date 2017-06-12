# Definition for singly-linked list.
#class ListNode(object):
# def __init__(self, x):
     #self.val = x
     #self.next = None

class Solution(object):

    def getListNum(self, l1):
        c = l1 
        num = 0 
        l = 0 
        while c != None: 
            l++ 
            num *= 10
            num += c.val
            c = c.next

        out = 0 
        while num > 0: 
            out += num // (10 ** (l-1)) 
            l-- 
            out *= 10

        return out 


    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        a = self.getListNum(l1) 
        b = self.getListNum(l2) 

        c = a + b 
        
        first = ListNode(c % 10) 
        last = first
        c /= 10 
        while c > 0:
            curr = ListNode(c % 10)
            curr.next = None
            last.next = curr
            last = curr
            c /= 10 

        return first 
