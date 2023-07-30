#Global
child_id = (10, 20, 30, 40, 50)
chocolates_rec = [12, 5, 3, 4, 6]

def calc_tot():
    global chocolates_rec
    return sum(chocolates_rec)

def reward(child_id_rec, extras):
    global child_id
    global chocolates_rec
    
    if child_id_rec not in child_id:
        print("Child id is invalid")
        return
    if extras<1:
        print("Extra Chocolates is less than 1"
              )
        return
    
    index_chocs = child_id.index(child_id_rec)
    chocolates_rec[index_chocs] += extras
    print(chocolates_rec)
    
print(calc_tot())
reward(60, -1)

# loops: while/for ==> break
# func: if ==> return