def ans(l, d):
    n = len(l)
    numP = numE = numO = 0
    for i in range(1, n, 2):
        doc = l[i]
        if doc == "P":
            numP += 1
        if doc == "O":
            numO += 1
        if doc == "E":
            numE += 1
            
    m = max(numE, numO, numP)
    if m == numP:
        return d["P"]
    if m == numO:
        return d["O"]
    if m == numE:
        return d["E"]
    
# driver
l = [301, "P", 302, "P", 305, "E", 401, "E", 656, "E"]
d = {"P": "Pedia", "E": "ENT", "O": "Ortho"}
print(ans(l, d))