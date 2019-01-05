#Print out user input number of ?

# Prompt user
while True:
    n = int (input("Positive integer: "))
    if n > 0:
        break

#Print out ?s
for i in range(n):
    print("?",end="")
print()
