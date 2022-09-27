stk=[]
top=-1
def line():
    print('~'*100)
def isEmpty():
    global stk
    if stk==[]:
        print("Stack is empty!!!")
    else:
        None
def push():
    global stk
    global top
    empno=int(input("Enter the employee number to push:"))
    ename=input("Enter the employee name to push:")
    stk.append([empno,ename])
    top=len(stk)-1
def display():
    global stk
    global top
    if top==-1:
        isEmpty()
    else:
        top=len(stk)-1
        print(stk[top],"<-top")
    for i in range(top-1,-1,-1):
        print(stk[i])
def pop_ele():
    global stk
    global top
    if top==-1:
        isEmpty()
    else:
        stk.pop()
        top=top-1
def main():
    while True:
        line()
        print("1. Push")
        print("2. Pop")
        print("3. Display")
        print("4. Exit")
        ch=int(input("Enter your choice:"))
        if ch==1:
            push()
            print("Element Pushed")
        elif ch==2:
            pop_ele()
        elif ch==3:
            display()
        else:
            print("Invalid Choice")

main()