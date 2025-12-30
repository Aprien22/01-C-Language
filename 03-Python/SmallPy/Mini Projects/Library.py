import os

class Books:
    def __init__(self, title, author, year, is_available):
        self.title = title
        self.author = author
        self.year = year
        self.is_available = is_available

    def display_info(self):
        availability = "Available" if self.is_available else "Not Available"
        return f"Title: {self.title}\nAuthor: {self.author}\nYear: {self.year}\nStatus: {availability}"
    

class Library:
    def __init__(self):
        self.catalog = []

    def add_book(self, book):
        titles = []
        for b in self.catalog:
            titles.append(b.title)
        if book.title not in titles:
            self.catalog.append(book)
            print(f"{book.title} added successfully!\n")
        else:
            print("This book is already in the catalog.")
        
    def list_books(self):
        os.system('cls')
        print("Library Catalogue:")
        for book in self.catalog:
            print(book.display_info())
            print()
        
        input("Press Enter to continue...")

    def by_title(self, title):
        for book in self.catalog:
            if book.title == title:
                return book
        return None
    
    def by_author(self, author):
        results = []
        for book in self.catalog:
            if book.author == author:
                results.append(book)
        return results
    
    def remove_book(self, title):
        self.catalog = [book for book in self.catalog if book.title != title]

def main():
    library = Library()
    books = [
        Books("1984", "George Orwell", 1949, True),
        Books("To Kill a Mockingbird", "Harper Lee", 1960, True),
        Books("The Great Gatsby", "F. Scott Fitzgerald", 1925, False),
        Books("Harry Potter 1", "JK Rowling", 2000, True),
        Books("Harry Potter 2", "JK Rowling", 2002, True),
    ]
    for book in books:
        library.add_book(book)

    while True:
        os.system('cls')
        print("=== Library Menu ===")
        print("1. Add Book")
        print("2. List Books")
        print("3. Remove Book")
        print("4. Search Book by Title")
        print("5. Search Book by Author")
        print("6. Exit")
        choice = input("Choose an option: ")

        if choice == '1':
            user_add_book(library)
        elif choice == '2':
            library.list_books()
        elif choice == '3':
            user_remove_book(library)
        elif choice == '4':
            user_search_by_title(library)
        elif choice == '5':
            user_search_by_author(library)
        elif choice == '6':
            print("Exiting the library system.")
            break
        else:
            print("Invalid choice. Please try again.\n")

def user_add_book(library):
    while True:
        os.system('cls')
        title = input("Enter book title: ")
        author = input("Enter book author: ")
        year = input("Enter publication year: ")
        is_available = input("Is the book available? (yes/no): ").lower().strip() == 'yes'
        book = Books(title, author, year, is_available)
        library.add_book(book)
        input("Press Enter to continue...")

        continue_adding = input("Do you want to add another book? (yes/no): ").lower().strip()
        if continue_adding != 'yes':
            break

def user_search_by_title(library):
    os.system('cls')

    title = input("Enter the title of the book to search: ")
    book = library.by_title(title)
    if book:
        print(book.display_info())
    else:
        print("Book not found.")
    input("Press Enter to continue...")

def user_search_by_author(library):
    os.system('cls')

    author = input("Enter the author of the book to search: ")
    books = library.by_author(author)
    if books:
        for book in books:
            print(book.display_info())
            print()
    else:
        print("No books found by that author.")
    input("Press Enter to continue...")

def user_remove_book(library):
    os.system('cls')

    title = input("Enter the title of the book to remove: ")
    library.remove_book(title)
    print(f"{title} has been removed from the catalog (if it existed).")
    input("Press Enter to continue...")

if __name__ == "__main__":
    main()