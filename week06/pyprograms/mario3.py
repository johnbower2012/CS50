#Print out user input number of #

# Prompt user
while True:
    n = 1+int (input("Positive integer: "))
    if n > 0:
        break

#Print out #s
for i in range(1,n):
    for j in range(n-i):
        print(" ",end="")
    for j in range(i):
        print("#",end="")
    print(" ",end="")
    for j in range(i):
        print("#",end="")
    for j in range(n-i):
        print("",end="")
    print()

