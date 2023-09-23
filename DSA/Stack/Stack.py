# Prefix, Infix, Postfix and their Evaluation

class Stack:
    def __init__(self):
        self.array = []
    def push(self, item):
        self.array.append(item)
    def pop(self):
        if self.array:
            return self.array.pop()
        else:
            print("> Stack is Empty!")
    def peek(self):
        if Stack.isEmpty(self):
            print("> Stack Empty!")
            return 
        print(f"> Top of the Stack: {self.array[-1]}")
    def isEmpty(self):
        if stack.array == []:
            return True
        return False
    def display(self):
        if Stack.isEmpty(self):
            print("> Stack Empty!")
            return 
        print("Stack: ")
        print("> Top of the Stack ")
        for i in range(len(self.array)-1, -1, -1):
            print(f"> {self.array[i]}")
        print("> Bottom of the Stack")
    def search(self, item):
        if Stack.isEmpty(self):
            print("> Stack is Empty!")
            return 
        if item in self.array:
            print(f"> {item} found!")
            print(f"> @ Position {self.array.index(item) + 1} from Bottom\n")
        else:
            print(f"> {item} not found!")
    def clear(self):
        self.array = []
        

stack = Stack()

stack.pop()
stack.display()
