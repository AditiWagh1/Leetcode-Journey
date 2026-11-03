# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        # Step 1: Count total nodes
        def count_nodes(node):
            if not node:
                return 0
            return 1 + count_nodes(node.left) + count_nodes(node.right)
        
        total_nodes = count_nodes(root)
        
        # Step 2: Validate indices (1-indexed)
        def dfs(node, idx):
            if not node:
                return True
            if idx > total_nodes:
                return False
            return dfs(node.left, 2 * idx) and dfs(node.right, 2 * idx + 1)
        
        return dfs(root, 1)
        