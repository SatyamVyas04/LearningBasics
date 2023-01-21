# # input - dict
# correct - keys
# tbc - values
# wrong - length not matches
# wrong - >2 incorrect
# almost correct - <=2 incorrect
# correct - else

def find_correct(d):
    keys = list(d.keys())
    vals = list(d.values())
    correct = almost = wrong = 0
    
    for i, word in enumerate(keys):
        tbc = vals[i]
        
        if len(tbc)!=len(word):
            wrong+=1
            continue
         
        galtiyan = 0
        for i in range(len(tbc)): # Satyam Shtyam
            ch = tbc[i]
            correctch = word[i]
            if ch != correctch:
                galtiyan += 1
                
        if galtiyan>2:
            wrong+=1
        elif galtiyan<=2 and galtiyan!=0:
            almost+=1
        elif galtiyan==0:
            correct+=1
            
    return [correct, almost, wrong]


# driver function
inp = {"THEIR":"THEIR", "BUSINESS":"BISINESS", 
       "WINDOWS":"WINDMILL", "WERE":'WEAR', "SAMPLE":"SAMPLE"}
ans = find_correct(inp)
print(ans)