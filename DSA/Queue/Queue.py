class Queue:
    def __init__(self):
        self.array = []
        
    def enqueue(self, item):
        self.array.append(item)
        
    def dequeue(self):
        if self.is_empty():
            return None  
        return self.array.pop(0)
    
    def get_front(self):
        if self.is_empty():
            return None
        return self.array[-1]
    
    def get_back(self):
        if self.is_empty():
            return None
        return self.array[0]
    
    def is_empty(self):
        return len(self.array) == 0
    
    def size(self):
        return len(self.array)
    
    def display(self):
        if self.is_empty():
            print("> Queue Empty!")
            return
        print("Queue:")
        print("> Front of the Queue")
        for item in reversed(self.array):
            print(f"> {item}")
        print("> Back of the Queue")
    
    def search(self, item):
        if self.is_empty():
            print("> Queue is Empty!")
            return
        if item in self.array:
            print(f"> {item} found!")
            print(f"> {self.array.index(item) + 1} in Queue\n")
        else:
            print(f"> {item} not found!")

# Basic methods of a Queue
# enqueue: add element at the front 
# dequeue: remove element at front 
# front: returns element at front 
# back: returns element at back
# display: prints the queue properly 
# search: search for an element in queue
# size: returns count of elements in the queue
# is_empty: checks for underflow
# is_full: checks for overflow
# clear: free space 