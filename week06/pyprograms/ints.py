def main():
    x = int (input("number: "))
    y = int (input("number: "))

    print(f"{x} plus {y} is {x + y}")
    print(f"{x} minus {y} is {x - y}")
    print(f"{x} times {y} is {x * y}")
    print(f"{x} truly-divided by {y} is {x / y}")
    print(f"{x} floor-divided by {y} is {x // y}")
    print(f"remainder of {x} divided by {y} is {x % y }")

if __name__ == "__main__":
    main()
