import sys
book = [
    "John",
    "Jessica",
    "Ivan",
    "Jesse",
    "Mama",
    "Baba"]

name = input("Name: ")
if name in book:
    print(f"Calling {name}")
else:
    print("Quitting")
