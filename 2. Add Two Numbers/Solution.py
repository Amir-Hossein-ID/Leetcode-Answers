from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ans = ListNode()
        last = ans
        l = 0
        while l1.next or l2.next:
            l = l + l1.val + l2.val
            last.val = l%10
            l = l//10
            last.next=ListNode()
            last = last.next
            l1 = l1.next if l1.next else ListNode()
            l2 = l2.next if l2.next else ListNode()
        l = l + l1.val + l2.val
        last.val = l%10
        l = l//10
        if l:
            last.next = ListNode(l)
        return ans
