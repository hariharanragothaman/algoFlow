from typing import List


def postorder_traversal(root: TreeNode) -> List[int]:
    result = []
    if root is None:
        return result

    stack = [root]
    while stack:
        node = stack.pop()
        if node:
            result.append(node.val)
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)

    return result[::-1]
