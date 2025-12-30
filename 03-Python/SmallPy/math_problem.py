print("Basic Calculator")

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

print(f"SUM: {x} + {y} = {sum}")
print(f"DIFFERENCE: {x} - {y} = {difference}")
print(f"PRODUCT: {x} * {y} = {product}")
print(f"QUOTIENT: {x} / {y} = {quotient:.2f}")
print(f"POWER: {x} ** {y} = {power:,}")


