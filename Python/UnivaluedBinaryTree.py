"""
965. Univalued Binary Tree
Easy

A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isUnivalTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        
        if root == None :
            return True
        
        return self.helper(root.left, root.val) and self.helper(root.right, root.val)
    
    def helper(self, root, val):
        if root == None : return True
        
        return root.val == val and self.helper(root.left, val) and self.helper(root.right, val)
        