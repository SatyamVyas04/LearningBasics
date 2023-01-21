# from Req_gems, take element
# find its index in gems list
# same index is the index of price
# multiply by quantity, present at same index as req, gems

# given:
#     1) Gems: [a, b, c, d]               - i1
#     2) Price: [100, 100, 200, 300]      - i1
#     3) Req_Gems: [a, c]                 - i2
#     4) Quantity: [2, 4]                 - i2
    
#     Cost: 100*2 + 200*4

def ans(gems, price, req, quantity):
    total = 0
    for i in range(len(req)):
        element = req[i] #Take element at index i in req
        if element not in gems:
            return -1
        #if "not in gems" condition is not hit :)
        j = gems.index(element) #Index of element gem in gems
        p = price[j] #Price of required element
        total += p*quantity[i] # multiply by quantity and += to total
    return total
        
# driver
gems = ["a", "b", "c", "d"]
price = [100, 100, 200, 300]
req = ["a", "e"]
quantity = [2, 5]
print(ans(gems, price, req, quantity), "ANS")




