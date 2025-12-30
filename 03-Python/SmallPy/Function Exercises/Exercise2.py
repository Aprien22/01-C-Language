# Square Calculation
def calculate_square(num: int) -> int:
    """Calculatre the square of a number."""
    return num * num

numbers = [1, 2, 3, 4, 5]
for num in numbers:
    squared = calculate_square(num)
    print(f"The square of {num} is {squared}")

print("=" * 40)

def print_address(name: str, street: str, city: str, state: str, zip_code: str) -> str:
    """Format and return a mailing address."""
    return f"{name}\n{street}\n{city}, {state} {zip_code}"

list_of_addresses = [
    ("John Doe", "123 Elm St", "Springfield", "IL", "62701"),
    ("Jane Smith", "456 Oak St", "Metropolis", "NY", "10001"),
    ("Alice Johnson", "789 Pine St", "Gotham", "NJ", "07097")
]

for address in list_of_addresses:
    formatted_address = print_address(*address) # uses unpacking *args to pass tuple elements as arguments
    print(formatted_address)
    print("-" * 20)

print("=" * 40)

def is_even(num: int) -> bool:
    """Check if a number is even."""
    return num % 2 == 0

test_numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
for num in test_numbers:
    if is_even(num):
        print(f"{num} is even.")
    else:
        print(f"{num} is odd.")

