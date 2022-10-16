def main(tag, letter):
    if letter in ["A", "E", "I", "O", "U"]:
        return "Arrest"
    if 0 in tag:
        return "Arrest"
    else:
        for i in range(len(tag)-1):
            if (tag[i]+tag[i+1])%2!=0:
                return "Arrest"
        return "Allowed"              

tag = list(input())
letter = tag.pop(2).upper()
tag.pop(-3)
tag = [eval(num) for num in tag]
print(main(tag, letter))