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


bst = BST()
bst.insert(Node(5))
bst.insert(Node(3))
bst.insert(Node(7))
bst.insert(Node(2))
bst.insert(Node(8))
bst.insert(Node(4))
bst.display()
