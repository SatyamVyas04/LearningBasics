# inp = "abcd"
# expected_out = "zyxv"
# for i in range(len(inp)):
#    print(inp[i], f"{ord(inp[i])}".ljust(4), f"{ord(expected_out[i])}".rjust(4), expected_out[i])

for i in range(65, 78):
    print(chr(i), i, end=" ")
print()
for i in range(78, 91):
    print(chr(i), i, end=" ")
print()
print()
for i in range(65, 78):
    print(chr(i), i, end=" ")
print()
for i in range(90, 77, -1):
    print(chr(i), i, end=" ")
print()

# inp = "hello"
# for i in inp:
#     if ord(i) in range(ord("a"), ord("z")+1):
#         print(chr(219-ord(i)), end=" ")
#     else:
#         print(chr(155-ord(i)), end=" ")