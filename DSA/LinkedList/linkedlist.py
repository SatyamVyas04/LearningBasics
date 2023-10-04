class Node:
    def __init__(self, data: int):
        self.data = data
        self.next: Node | None = None
    
    
class LinkedList:
    def __init__(self):
        self.head: Node | None = None
        self.tail: Node | None = None
        
    def __iter__(self):
        node = self.head
        while node:
            yield node.data
            node = node.next
            
    def __len__(self):
        return sum(1 for _ in self)
    
    def insert_node(self, index: int, data: int):
        new_node = Node(data)
        if index == 0:
            new_node.next = self
        elif index == -1:
            traverse = self
            while traverse.next != None:
                traverse = traverse.next
            traverse.next = new_node
        elif index<-1 and index>len(self):
            print("IndexError!")
        else:
            traverse = self
            while index>1:
                traverse = traverse.next
            new_node.next = traverse.next
            traverse.next = new_node
        
    def delete_node(self, index:int):
        if index == 0:
            self = self.next
        if index == -1:
            traverse = self
            while traverse.next.next != None:
                
            

    