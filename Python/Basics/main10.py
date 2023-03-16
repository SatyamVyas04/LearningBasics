from Conversion import lengthconversion as lc

try:
    a = int(input("\nEnter a length to convert: "))
    mode = int(input("\nAvailable modes of conversions are:\
        \n1) Feet to Inches\
        \n2) Inches to Feet\
        \n3) Kilometres to Miles\
        \n4) Miles to Kilometres\
        \n5) Help\
        \nEnter (1/2/3/4/5) to choose mode of conversion: "))
    print()

    if mode == 1:
        print(a, "feet is equal to", lc.feettoinch(a), "inches")
    if mode == 2:
        print(a, "inches is equal to", lc.inchtofeet(a), "feet")
    if mode == 3:
        print(a, "kilometre is equal to", lc.kmtomile(a), "miles")
    if mode == 4:
        print(a, "miles is equal to", lc.miletokm(a), "kilometre")
    if mode == 5:
        help(lc)

except ValueError:
    print("Invalid Input")


