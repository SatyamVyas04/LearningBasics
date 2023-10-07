class Node:
    def __init__(self, data):
        self.prev: Node | None = None
        self.data: int = data
        self.next: Node | None = None
    
class DLL:
    def __init__(self):
        self.head: Node | None = None
        self.tail: Node | None = None
    
    def __iter__(self):
        node = self.head
        while node:
            yield node.data
            node = node.next
    
    def __repr__(self):
        return '->'.join([str(item) for item in self])
    
    def __len__(self):
        return sum(1 for _ in self)
    
    def insert_node(self, index, data):
        new_node = Node(data)
        if len(self) == 0:
            self.head = self.tail = new_node
            return
        if index == 0:
            self.head.prev = new_node
            new_node.next = self.head
            self.head = new_node
        elif index == -1 or index == len(self):
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node
        elif index < -1 and index > len(self):
            print("IndexError!")
        else:
            traverse = self.head
            for _ in range(index):
                temp = temp.next
            temp.previous.next = new_node
            new_node.previous = temp.previous
            new_node.next = temp
            temp.previous = new_node
            
    def delete_node(self, index: int):
        length = len(self)
        delete_node = self.head
        if length == 1:
            self.head = self.tail = None
        elif index == 0:
            self.head = self.head.next
            self.head.prev = None
        elif index == length - 1 or index == -1:
            delete_node = self.tail
            self.tail = self.tail.prev
            self.tail.next = None
        elif not -1 <= index <= length - 1:        
            print("IndexError!")
            return None    
        else:
            temp = self.head
            prev = None
            current_index = 0
            while temp is not None and current_index < index:
                prev = temp
                temp = temp.next
                current_index += 1
            delete_node = temp
            temp.next.prev = temp.prev
            temp.prev.next = temp.next
        return delete_node.data
    

dll = DLL()
for i in range(1, 11):
    dll.insert_node(-1, i)

print(len(dll))
print(repr(dll))

print(dll.delete_node(0))
print(repr(dll))

print(dll.delete_node(-1))
print(repr(dll))

print(dll.delete_node(6))
print(repr(dll))

# Basic Implementation Done