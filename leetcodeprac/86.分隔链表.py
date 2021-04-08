#
# @lc app=leetcode.cn id=86 lang=python3
#
# [86] 分隔链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        while pre.next and pre.next.val < x:
            pre = pre.next
        if pre.next is None: return dummy.next
        
        cur = pre.next
        post = pre
        while cur:
            if cur.val >= x: 
                post = cur
                cur = cur.next 
            else: 
                # 删除原先位置的cur节点
                post.next = post.next.next
                # 插入cur，更新pre
                tmp = pre.next
                pre.next = cur
                cur.next = tmp
                pre = cur
                # 更新cur
                cur = post.next
        return dummy.next



            
# @lc code=end

