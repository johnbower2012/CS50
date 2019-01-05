# Get someones initials
s = input("name: ")
initials=""
for c in s:
    if c.isupper():
        initials += c
print(initials)
