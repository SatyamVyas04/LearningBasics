list_1 = list(eval(input('Enter the elements for list 1 (numbers only): ')))
list_2 = list(eval(input('Enter the elements for list 2 (numbers only): ')))
sum_list1_and_list2 = []

if len(list_1) == len(list_2):
    for i in range(0, len(list_2)):
        p1 = list_1[i] + list_2[i]
        sum_list1_and_list2.append(p1)

elif len(list_1) > len(list_2):
    for i in range(0, len(list_2)):
        p1 = list_1[i] + list_2[i]
        sum_list1_and_list2.append(p1)
    sum_list1_and_list2.append(list_1[len(list_2):])

else:
    for i in range(0, len(list_1)):
        p1 = list_1[i] + list_2[i]
        sum_list1_and_list2.append(p1)
    sum_list1_and_list2.append(list_2[len(list_1):])

print('The Sum of list 1 and list 2 is ', sum_list1_and_list2)

