# Greetings
def greetings(*name: str) -> str:
    """Return a greeting message."""
    for n in name:
        print(f"Hello, {n}!")


greetings("Alice", "Bob", "Charlie", "David")
print("=" * 40)

def calculate_area(length: float, width: float) -> float:
    """Calculate the area of a rectangle."""
    return length * width

list_of_dimensions = [
    (5.0, 7.0),     # length, width
    (7.5, 4.2),         
    (10.0, 6.5),
    (12.3, 8.4)
]
for dimensions in list_of_dimensions:
    area = calculate_area(*dimensions)
    print(f"Length: {dimensions[0]}, Width: {dimensions[1]} => Area: {area:.1f}")

print("=" * 40)

def temperature_conversion(type: int, temp: float) -> float:
    """Convert temperature between Celsius and Fahrenheit."""
    if type == 1:  # Celsius to Fahrenheit
        return (temp * 9/5) + 32
    elif type == 2:  # Fahrenheit to Celsius
        return (temp - 32) * 5/9
    else:
        raise ValueError("Invalid type. Use 1 for Celsius to Fahrenheit and 2 for Fahrenheit to Celsius.")
    
list_of_temps = [
    (1, 0),      # Celsius to Fahrenheit   
    (1, 100),    
    (2, 32),     # Fahrenheit to Celsius
    (2, 212),
    (0, 50),
    (3, 75),
    (1, -40),
]
for temps in list_of_temps:
    try:
        converted = temperature_conversion(*temps)
        if temps[0] == 1:
            print(f"{temps[1]}°C is equal to {converted:.1f}°F")
        else:
            print(f"{temps[1]}°F is equal to {converted:.1f}°C")
    except ValueError as e:
        print(e)
