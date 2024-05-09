# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def invertTree(self, root):
        self.rev(root)
        return root
    def rev(self, r):
        if r == None:
            return
        r.right, r.left = r.left, r.right
        self.rev(r.right)
        self.rev(r.left)
