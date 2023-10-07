class Node:
    def __init__(self, data: int):
        self.data = data
        self.next: Node | None = None


class LinkedList:
    def __init__(self):
        self.head: Node | None = None

    def __iter__(self):
        node = self.head
        while node:
            yield node.data
            node = node.next

    def __len__(self):
        return sum(1 for _ in self)

    def __repr__(self):
        return "->".join(str(item) for item in iter(self))

    def insert_node(self, index: int, data: int):
        new_node = Node(data)
        if len(self) == 0:
            self.head = new_node
            return
        if index == 0:
            new_node.next = self.head
        elif index == -1 or index == len(self):
            traverse = self.head
            while traverse != None and traverse.next != None:
                traverse = traverse.next
            traverse.next = new_node
        elif index < -1 and index > len(self):
            print("IndexError!")
        else:
            traverse = self.head
            while index > 1:
                traverse = traverse.next
                index -= 1
            new_node.next = traverse.next
            traverse.next = new_node

    def delete_node(self, index: int):
        if len(self) == 1:
            self.head = self.tail = None
        if index == 0:
            delete_node = self.head
            self.head = self.head.next
            return delete_node.data
        elif index == -1 or index == len(self):
            delete_node = None
            traverse = self.head
            while traverse.next.next != None:
                traverse = traverse.next
            delete_node = traverse.next
            traverse.next = None
            return delete_node.data
        elif index > 0 and index <= len(self) - 1:
            temp = self.head
            prev = None
            current_index = 0
            while temp is not None and current_index < index:
                prev = temp
                temp = temp.next
                current_index += 1
            delete_node = temp
            prev.next = temp.next
            return delete_node.data
        else:
            print("IndexError!")
            return None


ll = LinkedList()
for i in range(10):
    ll.insert_node(i, i + 1)

print(len(ll))
print(repr(ll))

print(ll.delete_node(0))
print(repr(ll))

print(ll.delete_node(-1))
print(repr(ll))

print(ll.delete_node(6))
print(repr(ll))

# Basic Implementation Done