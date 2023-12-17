# TODO
b = 0
s = True
while s:
    b = input("Height: ")
    if b.isdigit():
        if int(b) > 0 and int(b) < 9:
            s = False
a = int(b)
for i in range(a):
    print(" " * (a - i - 1), end="")
    print("#" * (i + 1), end="")
    print("  ", end="")
    print("#" * (i + 1), end="")
    print()