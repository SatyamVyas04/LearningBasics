# Stack Implementation
def isEmpty(stack):
    if stack == []:
        return True
    else:
        return False
def Push(stack, item):
    stack.append(item)
    top = len(stack) - 1
def Pop(stack):
    if isEmpty(stack):
        return "Underflow"
    else:
        item = stack.pop()
        if len(stack) == 0:
            top = None
        else:
            top = len(stack) - 1
        return item
def Peek(stack):
    if isEmpty(stack):
        return "Underflow"
    else:
        top = len(stack) - 1
        return stack[top]
def Display(stack):
    if isEmpty(stack):
        print("Stack Empty")
    else:
        top = len(stack) - 1
        print(stack[top], "<-- Top")
        for a in range(top-1, -1, -1):
            print(stack[a])

def Driver():
    Stack = []
    top = None
    while True:
        print("".ljust(20, "-"))
        print("Stack Operations")
        print("1. Push")
        print("2. Pop")
        print("3. Peek")
        print("4. Display Stack")
        print("5. Exit")
        ch = int(input("Enter your choice(1-5): "))
        if ch == 1:
            item = int(input("Enter item: "))
            Push(Stack, item)
            print()
        elif ch == 2:
            item = Pop(Stack)
            if item == "Underflow":
                print("Underflow! Stack is Empty!")
                print()
            else:
                print("Popped item is", item)
                print()
        elif ch == 3:
            item = Peek(Stack)
            if item == "Underflow":
                print("Underflow! Stack is Empty!")
                print()
            else: 
                print("The topmost item is", item)
                print()
        elif ch == 4:
            Display(Stack)
            print()
        elif ch == 5:
            print("Thank you!")
            print()
            break
        else: 
            print("Invalid Choice")
