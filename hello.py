def add(a: int, b: int) -> int:
    return a + b

x: int = int(input("Enter first number: "))
y: int = int(input("Enter second number: "))

result: int = add(x ,y)
print(f"The sum of {x} and {y} is {result}")

