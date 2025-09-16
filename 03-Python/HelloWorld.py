# Learning Python
name = input("Hello there! What's your name? ")

idealAge = 0

ages = {
    12 : "a child",
    18 : "a teenager",
    25 : "an adult",
    35 : "a middle-aged adult",
}

colors = {
    "blue": "ocean",
    "green": "peaceful",
    "yellow": "serene",
    "red": "warm"
}

while True:
    # Ask for age and favorite color
    age = input("How old are you? ")
    color = input("What's your favorite color? ")
    day = (input("What is the day today? [M/T/W/F/TH/F] - ")).lower()

    # Validate age input
    while not age.isdigit():
        print("Invalid age input. Please enter an appropriate age number.")
        age = input("How old are you? ")
    
    # Check for age category
    category = "a senior"
    for age_limit, age_category in sorted(ages.items()): 
        if int(age) < age_limit: 
            category = age_category
            break

    print(f"Nice to meet you, {name}! You're {int(age)}, meaning you're {category}.")


    # Output day-related message
    match day:
        case 'm': print("Monday")
        case 't': print("Tuesday")
        case 'w': print("Wednesday")
        case 'th': print("Thursday")
        case 'f': print("Friday")

    # Output color-related message
    if color.lower() in colors:
        print(f"{color.capitalize()} is {colors[color.lower()]}.")
    else:
        print(f"{color.capitalize()} is an interesting choice.")

    # Calculate ideal age
    idealAge = int(int(age) / 2 + 7)
    print(f"Based on your age and favorite color, your ideal age is {idealAge}.\n")

    # Ask user if they want to continue
    choice = input("Do you want to continue? (yes/no): ").lower()
    if choice != "yes":
        print("Thank you for using our program. Goodbye!")
        break
