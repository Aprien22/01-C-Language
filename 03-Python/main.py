# Python Language Cheat Sheet

# 1. Variables and Data Types
string_var = "Hello, World!"  # String
integer_var = 42              # Integer
float_var = 3.14              # Float
boolean_var = True            # Boolean
none_var = None               # NoneType

# 2. Lists, Tuples, and Dictionaries
my_list = [1, 2, 3, 4, 5]              # List (mutable)
my_tuple = (1, 2, 3, 4, 5)             # Tuple (immutable)
my_dict = {"name": "John", "age": 30}  # Dictionary

# 3. Input and Output
name = input("What is your name? ")  # Input
print("Your name is " + name)        # Output (concatenation)
print(f"Your name is {name}")        # Output (f-string)

# 4. Conditional Statements
age = 20
if age >= 18:
    print("You are an adult")
elif age >= 13:
    print("You are a teenager")
else:
    print("You are a child")

# 5. Loops
# For loop
for i in range(5):
    print(i)

# While loop
count = 0
while count < 5:
    print(count)
    count += 1

# 6. Functions
def greet(name):
    return f"Hello, {name}!"

message = greet("Alice")
print(message)

# 7. List Comprehensions
squares = [x**2 for x in range(10)]
print(squares)

# 8. Exception Handling
try:
    result = 10 / 0
except ZeroDivisionError:
    print("Cannot divide by zero!")

# 9. File I/O
# Writing to a file
with open("example.txt", "w") as file:
    file.write("Hello, File!")

# Reading from a file
with open("example.txt", "r") as file:
    content = file.read()
    print(content)

# 10. Modules
import math
print(math.pi)

# 11. Classes and Objects
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def introduce(self):
        return f"My name is {self.name} and I'm {self.age} years old."

person = Person("John", 30)
print(person.introduce())

# 12. Lambda Functions
multiply = lambda x, y: x * y
print(multiply(5, 3))

# 13. List Methods
my_list = [1, 2, 3, 4, 5]
my_list.append(6)      # Add an element
my_list.remove(3)      # Remove an element
popped = my_list.pop() # Remove and return the last element
my_list.sort()         # Sort the list in-place

# 14. String Methods
text = "hello, world"
print(text.capitalize())  # Capitalize first letter
print(text.upper())       # Convert to uppercase
print(text.split(", "))   # Split string into list

# 15. Sets
my_set = {1, 2, 3, 4, 5}
my_set.add(6)             # Add an element
my_set.remove(3)          # Remove an element
print(2 in my_set)        # Check if an element exists

# 16. Decorators
def my_decorator(func):
    def wrapper():
        print("Something is happening before the function is called.")
        func()
        print("Something is happening after the function is called.")
    return wrapper

@my_decorator
def say_hello():
    print("Hello!")

say_hello()