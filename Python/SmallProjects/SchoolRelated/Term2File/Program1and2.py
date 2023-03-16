# Stack Implementation
stack = []
print("\n# The Stack is empty as of now...\n")
def Push(element):
    stack.append(element)
    print(f'>> "{element}" has been added to the Stack\n')

def Pop():
    print(f">> Topmost Element '{stack[-1]}' has been removed from the stack\n")
    return stack.pop()
        
def Peek():
    print(f">> The Topmost Element in the Stack is '{stack[-1]}'")

def Display():
    top = len(stack) - 1
    print(">> The Stack looks like this in stack: ")
    print(stack[top], "<-- Top")
    for a in range(top-1, -1, -1):
        print(stack[a])
    print()
# Driver Program
Push(3)
Push(4)
Push(2)
Display()
Push(6)
Peek()
Pop()
Pop()
Push(6)
Display()
