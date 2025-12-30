# Quiz Project
import random  # Importing Libraries

# Questions Dictionary
questions = {
    "What is the powerhouse of the cell?": "Mitochondria",
    "The process of photosynthesis occurs in which part of the cell?": "Chloroplast",
    "The main component of DNA is?": "Nucleotide",
}

# Correct Responses
correct_responses = ["Correct +1 🥳", "You're on fire! 🔥", "Right answer! 👍"]

# User Input for Name
name = input("Hello, What's your name? ").strip().upper()

def sum(a: int, b: int) -> int:
    return a + b

def subtract(a: int, b: int) -> int:
    return a - b

def multiply(a: int, b: int) -> int:
    return a * b

def divide(a: int, b: int) -> int:
    if b != 0:
        return a / b
    else:
        print("Error: Division by zero is not allowed.")
        return None

# Main Menu Loop
while True:
    print("=" * 60)  # Separator line
    print(f"Hello {name}, Welcome to the MENU \n1. QandA\n2. Calculator\n3. Exit")
    choice = int(input("INPUT: ").strip())

    if choice == 1:
        # QandA Game
        while True:
            print("=" * 60)  # Separator line
            print(f"\nHello {name}, Welcome to the QUIZ GAME!")
            print("DIRECTION: Please answer the following questions:\n")
            
            # Shuffle Questions
            question_items = list(questions.items())
            random.shuffle(question_items)
            
            # Initialize Score
            scores = 0
            
            # Iterate through Questions
            for question, answer in question_items:
                print("=" * 60)  # Separator line
                user_answer = input(f"{question} ").strip()
                
                # Re-prompt until user provides a non-empty response
                while not user_answer:
                    print("Invalid response. Please provide an answer.")
                    user_answer = input(f"{question} ").strip()

                # Check Answer
                if user_answer.lower() == answer.lower() or user_answer.lower() == answer.lower() + 's':
                    scores += 1
                    print(random.choice(correct_responses))
                else:
                    print(f"Sorry, the correct answer is {answer} 🥲")

            # Display Final Score
            print("=" * 60)
            print(f"\nYour final score is {scores}/{len(questions)} 😁")
            
            # Congratulatory Message
            if scores == len(questions):
                print("Wow! Perfect score! You're a genius! 🎓")
            elif scores > len(questions) / 2:
                print("Great job! You know your stuff! 🌟")
            else:
                print("Better luck next time! Keep learning! 💪")

            # Play Again Prompt
            again = input("\nDo you want to play again? (Y/N) ").strip().upper()
            if again != 'Y':
                print("=" * 60)
                print("\nTHANKS FOR PLAYING QandA!\n")
                break

    elif choice == 2:
        # Calculator Game
        while True:
            print("=" * 60)
            first = int(input("First Number: "))
            second = int(input("Second Number: "))
            operation = input("Operation (+, -, *, /): ")
            print("=" * 60)
            
            # Validate input
            if operation not in ['+', '-', '*', '/']:
                print("Invalid operation. Please choose between +, -, *, /.")
                continue
    
            result = 0
            # Match operation
            match (operation):
                case '+':
                    result = sum(first, second)
                case '-':
                    result = subtract(first, second)
                case '*':
                    result = multiply(first, second)
                case '/':
                    result = divide(first, second)
            print("=" * 60)
            print(f"{first} {operation} {second} = {result}")

            # Play Again Prompt
            again = input("\nDo you want to play again? (Y/N) ").strip().upper()
            if again != 'Y':
                print("=" * 60)
                print("\nTHANKS FOR PLAYING CALCULATOR!\n")
                break

    elif choice == 3:
        # Exit Confirmation
        print("=" * 60)
        confirm_exit = input("\nAre you sure you want to exit? (Y/N) ").strip().upper()
        if confirm_exit == "Y":
            print("=" * 60)
            print("THANKS FOR USING THE PROGRAM!")
            break
    else:
        print("Invalid choice. Please select a valid option.")

