class Node:
    def __init__(self, value):
        self.left: Node | None = None
        self.right: Node | None = None
        self.value = value

    def __str__(self) -> str:
        return str(self.value)


class BST:
    def __init__(self):
        self.root: Node | None = None

    def empty(self) -> bool:
        return self.root is None

    def insert(self, node: Node) -> None:
        if self.empty():
            self.root = node
        else:
            current = self.root
            while True:
                if node.value < current.value:
                    if current.left is None:
                        current.left = node
                        break
                    current = current.left
                elif node.value > current.value:
                    if current.right is None:
                        current.right = node
                        break
                    current = current.right
                else:
                    print("> Value already exists! ")
                    break

    def insert_many(self, vals: list[int]) -> None:
        for i in vals:
            self.insert(Node(i))

    def delete(self, value):
        def delete_node(node, value):
            if node is None:
                return node

            if value < node.value:
                node.left = delete_node(node.left, value)
            elif value > node.value:
                node.right = delete_node(node.right, value)
            else:
                if node.left is None:
                    return node.right
                elif node.right is None:
                    return node.left

                node.value = self.get_min(node.right)
                node.right = delete_node(node.right, node.value)

            return node

        self.root = delete_node(self.root, value)

    def get_max(self, node: Node) -> int:
        if node is None:
            return self._get_max(self.root)
        return self._get_max(node)

    def _get_max(self, node: Node) -> int:
        if node is None:
            return None

        while node.right is not None:
            node = node.right

        return node.value

    def get_min(self, node: Node) -> int:
        if node is None:
            return self._get_min(self.root)
        return self._get_min(node)

    def _get_min(self, node: Node) -> int:
        if node is None:
            return None

        while node.left is not None:
            node = node.left

        return node.value

    def find(self, value) -> bool:
        root = self.root
        while root != None and root.value != value:
            if value < root.value:
                root = root.left
            else:
                root = root.right
        if root == None:
            return False
        else:
            return True

    def find_node(self, value) -> None:
        res = self.find(value)
        if not res:
            print(f"> Not Found {value}")
        else:
            print(f"> Found {value}")

    def display(self):
        def in_order_traversal(node):
            if node:
                in_order_traversal(node.left)
                print(node.value, end=" ")
                in_order_traversal(node.right)

        def pre_order_traversal(node):
            if node:
                print(node.value, end=" ")
                in_order_traversal(node.left)
                in_order_traversal(node.right)

        def post_order_traversal(node):
            if node:
                in_order_traversal(node.left)
                in_order_traversal(node.right)
                print(node.value, end=" ")

        in_order_traversal(self.root)
        print("--> Inorder Traversal")
        pre_order_traversal(self.root)
        print("--> PreOrder Traversal")
        post_order_traversal(self.root)
        print("--> PostOrder Traversal")


# Credits: https://stackoverflow.com/a/65865825
def print_tree(root, value="value", left="left", right="right"):
    print("\n> BINARY TREE")

    def display(root, value=value, left=left, right=right):
        """Returns list of strings, width, height, and horizontal coordinate of the root."""
        # No child.
        if getattr(root, right) is None and getattr(root, left) is None:
            line = "%s" % getattr(root, value)
            width = len(line)
            height = 1
            middle = width // 2
            return [line], width, height, middle

        # Only left child.
        if getattr(root, right) is None:
            lines, n, p, x = display(getattr(root, left))
            s = "%s" % getattr(root, value)
            u = len(s)
            first_line = (x + 1) * " " + (n - x - 1) * "_" + s
            second_line = x * " " + "/" + (n - x - 1 + u) * " "
            shifted_lines = [line + u * " " for line in lines]
            return [first_line, second_line] + shifted_lines, n + u, p + 2, n + u // 2

        # Only right child.
        if getattr(root, left) is None:
            lines, n, p, x = display(getattr(root, right))
            s = "%s" % getattr(root, value)
            u = len(s)
            first_line = s + x * "_" + (n - x) * " "
            second_line = (u + x) * " " + "\\" + (n - x - 1) * " "
            shifted_lines = [u * " " + line for line in lines]
            return [first_line, second_line] + shifted_lines, n + u, p + 2, u // 2

        # Two children.
        left, n, p, x = display(getattr(root, left))
        right, m, q, y = display(getattr(root, right))
        s = "%s" % getattr(root, value)
        u = len(s)
        first_line = (x + 1) * " " + (n - x - 1) * "_" + s + y * "_" + (m - y) * " "
        second_line = (
            x * " " + "/" + (n - x - 1 + u + y) * " " + "\\" + (m - y - 1) * " "
        )
        if p < q:
            left += [n * " "] * (q - p)
        elif q < p:
            right += [m * " "] * (p - q)
        zipped_lines = zip(left, right)
        lines = [first_line, second_line] + [a + u * " " + b for a, b in zipped_lines]
        return lines, n + m + u, max(p, q) + 2, n + u // 2

    lines, *_ = display(root, value, left, right)
    for line in lines:
        print(line)


bst = BST()
bst.insert_many([5, 3, 8, 2, 1, 4, 6, 7, 9, 10])
print_tree(bst.root)
bst.display()

bst.delete(5)
print_tree(bst.root)
bst.display()
