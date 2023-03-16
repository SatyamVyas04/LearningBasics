# Mean of means calculator
tuple1 = ((1, 2), (3, 4.15, 5.15), (7, 8, 12, 15))
main_mean_sum = 0
main_mean_base = 0
for i in range(len(tuple1)):
    mean = sum(tuple1[i])/len(tuple1[i])
    print(f'Mean element {i+1} :', mean)
    main_mean_sum += sum(tuple1[i])
    main_mean_base += len(tuple1[i])
main_mean = main_mean_sum/main_mean_base
print(f'Mean of means {main_mean}')