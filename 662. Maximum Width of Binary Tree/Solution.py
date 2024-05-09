# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def widthOfBinaryTree(self, root) -> int:
        max_i = 0
        nex = [(1,root)]
        num = 1
        while any(nex):
            fl = ll = -1
            lis = nex
            nex = []
            for j,i in lis:
                if i == None:
                    continue
                num += 1
                if i.left:
                    if fl == -1:
                        fl = j*2
                    ll = j*2
                    nex.append((j*2,i.left))
                if i.right:
                    if fl == -1:
                        fl = j*2+1
                    ll = j*2+1
                    nex.append((j*2+1,i.right))
            max_i = max(max_i, ll-fl+1)
        return max_i
