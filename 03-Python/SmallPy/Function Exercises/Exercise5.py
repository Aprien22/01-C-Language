def say_hello():
    """Print a simple greeting."""
    print("Hello, World!")

say_hello()

print("=" * 40)

def greet_user_with_color():
    """Greet the user and mention their favorite color."""
    name = input("Enter your name: ")
    color = input("Enter your favorite color: ")
    print(f"Hello, {name}! Your favorite color is {color}.")

greet_user_with_color()

print("=" * 40)


def greet_two_person(name1: str, name2: str):
    """Greet two persons by their names."""
    print(f"Hello, {name1} and {name2}!")   

greet_two_person("Alice", "Bob")


print("=" * 40)
def create_email(recepient: str, subject: str = "No Subject", body: str = "") -> str:

    """Create a formatted email string.
    
    Args:
        recepient (str): The email recipient.
        subject (str): The email subject.
        body (str): The email body.
    
    """
    email = f"To: {recepient}\nSubject: {subject}\n\n{body}"
    return email

email_content = create_email("john.doe@example.com", "Hello!", "This is a test email.")
email_content2 = create_email("jane.doe@example.com")
print(email_content)
print(email_content2)

print("=" * 40)

def calculate_volume(length: float, width: float, height: float) -> float:
    """Calculate the volume of a rectangular prism."""
    return length * width * height

volume = calculate_volume(width=4.0, height=5.0, length=6.0)

print(f"Volume: {volume}")
print("=" * 40)