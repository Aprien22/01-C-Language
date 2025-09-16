# Mini Library System
import os

def clearScreen() :
    os.system('cls' if os.name == 'nt' else 'clear')

def libraryCollection(books: list, pause: bool):
    books.sort()
    if len(books) == 0:
        print("Library is completely out of stock!")
    else : 
        for idx, book in enumerate(books, 1):
            print(f"{idx}. {book}")
    print("\n")
    if pause:
        input("Press Enter to return to the menu...") 



def userCollection(userBooks: list, pause: bool):
    if len(userBooks) == 0:
        print("You don't have any Books yet!")
    else : 
        for idx, book in enumerate(userBooks, 1):
            print(f"{idx}. {book}")
    print("\n")  
    if pause:
        input("Press Enter to return to the menu...") 



def addABook(books: list) :
    choice = 1
    while choice == 1:
        addBook = str(input("Which Book would you like to add?\n>>> "))
        books.append(addBook)
        print(f"'{addBook}' is added to the collection!")
        choice = int(input("\nWould you like to add another book (1 - YES | 0 - NO):\n>>> "))
        while choice > 1 or choice < 0:
            choice = int(input("INVALID INPUT! (1 - YES | 0 - NO):\n>>> "))
        print("\n")
    print("\n")
    input("Press Enter to return to the menu...")


def borrowABook(books: list, userBooks: list):
    print("===== AVAILABLE BOOKS =====")
    libraryCollection(books, False)

    choice = 0
    choice = int(input("Which Book would you like to borrow?\n>>> ")) - 1
    while choice < 0 or choice >= len(books):
        choice = int(input(f"Invalid Input! Must be (1 - {len(books)})\n>>> ")) - 1

    print(f"You borrowed '{books[choice]}'!")
    userBooks.append(books[choice])
    books.remove(books[choice])
    print("\n")
    input("Press Enter to return to the menu...")

def returnABook(books: list, userBooks: list):
    print("===== CURRENTLY BORROWED BOOKS =====")
    userCollection(userBooks, False)

    choice = int(input("Which Book would you like to return?\n>>> ")) - 1
    while choice < 0 or choice >= len(userBooks):
        choice = int(input(f"Invalid Input! Must be (1 - {len(userBooks)})\n>>> ")) - 1

    print(f"You returned '{userBooks[choice]}'!")
    books.append(userBooks[choice])
    userBooks.remove(userBooks[choice])
    print("\n")
    input("Press Enter to return to the menu...")




libraryBooks = ["To Kill a Mockingbird", "The Hunger Games", "Harry Potter: The Philosopher's Stones"]
userBooks = []
count = len(libraryBooks)


while True: 
    clearScreen()
    print("===== WELCOME TO YOUR MINI LIBRARY SYSTEM =====")
    print("Please select an option:")
    print("1. View Library")
    print("2. Add a Book")
    print("3. Borrow a Book")
    print("4. Return a Book")
    print("5. Check Currently Borrowed Books")
    print("6. Exit")

    choice = int(input(">>> ").strip())

    match choice:
        case 1:
            print("\n===== LIBRARY COLLECTION =====")
            libraryCollection(libraryBooks, True) 
        case 2:
            print("\n===== ADD A BOOK =====")
            addABook(libraryBooks)
        case 3:
            print("\n===== BORROW A BOOK =====")
            borrowABook(libraryBooks, userBooks)
        case 4:
            print("\n===== RETURN A BOOK =====")
            returnABook(libraryBooks, userBooks)
        case 5:
            print("\n===== RETURN A BOOK =====")
            userCollection(userBooks, True)
        case 6:
            break

print("Exiting Program....")


        

    



    

