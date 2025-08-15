class Student:
    def __init__(self):
        self.id = int(input("Enter the ID:"))
        self.name = input("Enter name:")
        self.roll = int(input("Enter roll number:"))
        self.branch = input("Enter branch name:")
        self.cgpa = float(input("Enter your cgpa:"))

    def display(self):
        print("ID is", self.id)
        print("Name is", self.name)
        print("Roll number is", self.roll) 
        print("Branch is", self.branch) 
        print("CGPA is", self.cgpa)

obj = Student()
obj.display()