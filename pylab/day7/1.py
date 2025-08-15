class Animal:
    def __init__(self, legs, canine):
        self.num_legs = legs
        self.canine = canine

class Dog(Animal):
    def __init__(self, breed):
        super().__init__(4, True)
        self.breed = breed

class Cat(Animal):
    def __init__(self, domestic):
        super().__init__(4, False)
        self.domestic = domestic

class Panther(Animal):
    def __init__(self, color):
        super().__init__(4, False)
        self.color = color

dog = Dog("Labrador")
cat = Cat(True)
panther = Panther("black")

print(f"The breed of dog is {dog.breed}")
print(f"Is the cat domesticated: {cat.domestic}")
print(f"Color of panther: {panther.color}")