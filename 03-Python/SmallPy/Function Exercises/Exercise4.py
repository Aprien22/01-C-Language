class Dog:
    """ Class Dog with Attributes name and breed
    
    Attributes:
        name (str): The name of the dog.
        breed (str): The breed of the dog.

    Methods:
        bark(): Prints a barking sound.
    
    """
    def __init__(self, name: str, bread: str):
        self.name = name
        self.breed = bread

    def bark(self):
        print("Woof! Woof!")


list_of_dogs = [
    ("Buddy", "Golden Retriever"),
    ("Max", "German Shepherd"),
    ("Bella", "Labrador Retriever"),
    ("Lucy", "Bulldog")
]

for dog_info in list_of_dogs:
    dog = Dog(*dog_info)
    print(f"Dog Name: {dog.name}, Breed: {dog.breed}")
    dog.bark()
    print("-" * 30)

help(len)