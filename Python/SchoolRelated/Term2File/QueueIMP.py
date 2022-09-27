# Queue Implementation
def isEmpty(queue):
    if queue == []:
        return True
    else:
        return False

def Enqueue(queue, item):
    queue.append(item)

def Dequeue(queue):
    if isEmpty(queue):
        return "Underflow"
    else:
        item = queue.pop(0)
        return item

def Peek(queue):
    if isEmpty(queue):
        return "Underflow"
    else:
        return queue[0]

def Display(queue):
    if isEmpty(queue):
        print("Queue Empty")
    else:
        print("Entry End --> ", end="")
        for a in range(len(queue)-1, 0, -1):
            print(queue[a], end=", ")
        print(queue[0], "<-- Exit End")
def Driver():
    Queue = []
    while True:
        print("".ljust(20, "-"))
        print("Queue Operations")
        print("1. Enqueue")
        print("2. Dequeue")
        print("3. Peek")
        print("4. Display Queue")
        print("5. Exit")
        ch = int(input("Enter your choice(1-5): "))
        if ch == 1:
            item = int(input("Enter item: "))
            Enqueue(Queue, item)
            print()
        elif ch == 2:
            item = Dequeue(Queue)
            if item == "Underflow":
                print("Underflow! Queue is Empty!")
                print()
            else:
                print("Dequeued item is", item)
                print()
        elif ch == 3:
            item = Peek(Queue)
            if item == "Underflow":
                print("Underflow! Queue is Empty!")
                print()
            else: 
                print("The item at exit end is", item)
                print()
        elif ch == 4:
            Display(Queue)
            print()
        elif ch == 5:
            print("Thank you!")
            print()
            break
        else: 
            print("Invalid Choice")
