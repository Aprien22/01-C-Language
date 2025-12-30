import math

def factorial(*args):
    results = []
    if not all(isinstance(number, (int, float)) for number in args):
        raise TypeError("All arguments must be numbers")
    for i, number in enumerate(args):
        result = math.factorial(number)
        print(f"args[{i}] = {number}! = {result}")
    return results



my_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
try:
    factorial(*my_list)
except TypeError as e:
    print(e)  # Output: All arguments must be numbers