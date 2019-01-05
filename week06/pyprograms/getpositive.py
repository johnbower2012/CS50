def main():
    x = get_positive_int("positive integer: ")
    print(x)

def get_positive_int(prompt):
    while True:
        n = int (input(prompt))
        if n > 0:
            break
    return n

if __name__ == "__main__":
    main()
