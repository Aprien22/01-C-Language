def add(a: int, b: int) -> int:
    return a + b

def subtract(a: int, b: int) -> int:
    return a - b

def multiply(a: int, b: int) -> int:
    return a * b

def divide(a: int, b: int) -> float:
    if b == 0:
        raise ValueError("Cannot divide by zero")
    return a / b

def pow(a: int, b: int) -> int:
    return a ** b

x = int(input("Enter first number: "))
y = int(input("Enter second number: "))

sum = add(x ,y)
difference = subtract(x, y)
product = multiply(x, y)
quotient = divide(x, y)
power = pow(x, y)

print(f"The sum of {x} and {y} is {sum}")
print(f"The difference of {x} and {y} is {difference}")
print(f"The product of {x} and {y} is {product}")
print(f"The quotient of {x} and {y} is {quotient}")
print(f"{x} raised to the power of {y} is {power:,}")


