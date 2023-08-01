# With this project, I intend to read names from text file using RegEX
# and learn to group data distinctly based on values

import re, csv

with open("data.txt", 'r', encoding="UTF8") as txtfile:
    tts = txtfile.readlines() # tts=Test-to-Search
    
    # Data Entry File Opened
    csvfile = open("data.csv", "w")
    fieldnames = ["Sr.", "FirstName", "LastName", "Street", "Locality", "Email", "Domain"]
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames, lineterminator="\n")
    
    # Entering HeaderRow in CSV File
    writer.writeheader()
    
    for index in range(0, len(tts), 5):
        line = tts[index]
        pattern = re.compile(r'^(\w+)\s([^\d]+)\n$') 
        # First name has to be a word, Last name can contain hyphens
        matches = pattern.findall(line)
        firstname, lastname = matches.pop()
        # print(firstname, lastname) # Later add to a CSV File
        
        line = tts[index+1]
        pattern = re.compile(r"^(\d{3}-\d{3}-\d{4})\n$")
        matches = pattern.findall(line)
        phonenumber = matches.pop()
        # print(phonenumber) # Later add to a CSV File
        
        line = tts[index+2]
        pattern = re.compile(r"^([a-zA-Z0-9-.'\s]*), ([a-zA-Z0-9-.'\s]*)\n$")
        matches = pattern.findall(line)
        street, locality = matches.pop()
        # print(street, locality) # Later add to a CSV File
        
        line = tts[index+3]
        pattern = re.compile("^([-\w\.]+@([\w-]+\.)+[\w-]{2,4})\n$")
        matches = pattern.findall(line)
        email, domain = matches.pop()
        domain = domain[:-1]
        # print(email, domain) # Later add to a CSV File
        # print([f"{index//5 + 1}", firstname, lastname, street, locality, email, domain])
        
        writer.writerow({"Sr.": f"{index//5+1}", 
                         "FirstName": firstname,
                         "LastName": lastname, 
                         "Street": street, 
                         "Locality": locality, 
                         "Email": email, 
                         "Domain": domain})
        
        print(f"Data from Line {index//5+1} entered Successfully in CSV File!")
    print("> Data Entry Complete")
    txtfile.close()
    csvfile.close()
print("> Thank You!\n")