def calculate_compound_interest(principal, rate, time, n=1, contribution=0):
  """Calculates compound interest.

  Args:
    principal: The principal amount.
    rate: The annual interest rate (as a decimal).
    time: The time in years.
    n: The number of times interest is compounded per year. Defaults to 1 (annually).

  Returns:
    The final amount after compound interest.
  """
  amount = principal * (1 + rate / n)**(n * time) + contribution * (((1 + rate / n)**(n * time) - 1) / (rate / n))
  return amount

# Calculate compound interest compounded annually
final_amount = calculate_compound_interest(1000, 0.05, 5, contribution = 100)
print(f"Final amount (annually): ${final_amount:.2f}")

# Calculate compound interest compounded monthly
final_amount_monthly = calculate_compound_interest(1000, 0.05, 5, 12, contribution = 100)
print(f"Final amount (monthly): ${final_amount_monthly:.2f}")


def format_text(text, bold=False, italic=False, color="black"):
  """Formats text with bold and/or italic styling.

  Args:
    text: The text to format.
    bold: Whether to apply bold styling. Defaults to False.
    italic: Whether to apply italic styling. Defaults to False.

  Returns:
    The formatted text (represented as a string with tags).
  """
  formatted_text = text
  if bold:
    formatted_text = "<b>" + formatted_text + "</b>"
  if italic:
    formatted_text = "<i>" + formatted_text + "</i>"
  if color:
    formatted_text = f"<font color='{color}'>{formatted_text}</font>"
  return formatted_text

print(format_text("Hello"))  # Output: Hello
print(format_text("Hello", bold=True))  # Output: <b>Hello</b>
print(format_text("Hello", italic=True))  # Output: <i>Hello</i>
print(format_text("Hello", bold=True, italic=True))  # Output: <b><i>Hello</i></b>


def connect_to_database(host="localhost", port=5432, user="default_user", password=""):
    """Connects to a PostgreSQL database.

    Args:
        host: The database host. Defaults to "localhost".
        port: The database port. Defaults to 5432 (PostgreSQL's default).
        user: The database username. Defaults to "default_user".
        password: The database password. Defaults to "".

    Returns:
        A database connection object (in a real application).  For this example, returns a formatted string.
    """
    connection_string = f"Connecting to database at host: {host}, port: {port} as user: {user}"
    # In a real application, you would use a database library (e.g., psycopg2)
    # to establish the connection.
    return connection_string

print(connect_to_database()) # Output: Connecting to database at host: localhost, port: 5432 as user: default_user
print(connect_to_database(host="db.example.com", user="admin", password="secret")) # Output: Connecting to database at host: db.example.com, port: 5432 as user: admin