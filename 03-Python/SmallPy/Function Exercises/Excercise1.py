print("Celsius to Fahrenheit Conversion")
def celsius_to_fahrenheit(celsius) -> float:
    """Convert Celsius to Fahrenheit."""
    return (celsius * 9/5) + 32

temperature_values = [0, 20, 37, 100]
for celsius in temperature_values:
    converted = celsius_to_fahrenheit(celsius)
    print(f"{celsius}°C is equal to {converted}°F")


print("=" * 40)
print("String Reversal")
def reverse_string(text: str) -> str:
    """Reverse the given string."""
    return text[::-1]

strings = ["hello", "world", "python", "programming"]
for s in strings:
    reversed_string = reverse_string(s)
    print(f"Original String: {s} - Reversed string: {reversed_string}")


print("=" * 40)
print("Prime Number Checker")
def is_prime(num: int) -> bool:
    """ Check if the number is a prime."""
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

numbers = [2, 3, 4, 5, 10, 13, 17, 19, 23]
for num in numbers:
    if is_prime(num):
        print(f"{num} is a prime number.")
    else:
        print(f"{num} is not a prime number.")



