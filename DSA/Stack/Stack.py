class Stack:
    def __init__(self):
        self.array = []

    def push(self, item):
        self.array.append(item)

    def pop(self):
        if self.is_empty():
            return None 
        return self.array.pop()

    def peek(self):
        if self.is_empty():
            return None
        return self.array[-1]

    def is_empty(self):
        return len(self.array) == 0

    def size(self):
        return len(self.array)

    def display(self):
        if self.is_empty():
            print("> Stack Empty!")
            return
        print("Stack:")
        print("> Top of the Stack")
        for item in reversed(self.array):
            print(f"> {item}")
        print("> Bottom of the Stack")

    def search(self, item):
        if self.is_empty():
            print("> Stack is Empty!")
            return
        if item in self.array:
            print(f"> {item} found!")
            print(f"> @ Position {len(self.array) - self.array.index(item)} from Top\n")
        else:
            print(f"> {item} not found!")

    def clear(self):
        self.array = []

# Basic Methods of a Stack
# push: adds a new element at top
# pop: removes top element
# peek: returns top element
# isEmpty or is_empty: checks for underflow
# isFull or is_full: check for overflow
# size: returns the number of elements in the stack
# search: find an element in the stack
# display: print the complete stack 
# clear: free space 