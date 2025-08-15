class Employee:
    def __init__(self):
        self.id=int(input("Enter the ID:"))
        self.name=input("Enter name:")
        self.salary=int(input("Enter your salary:"))
        self.companyname=input("Enter company name:")
        self.yoe=int(input("Enter year of experience:"))

    def display(self):
        print("Name is",self.name)
        print("ID is",self.id)
        print("Salary is",self.salary) 
        print("Company name is",self.companyname) 
        print("Year of experience",self.yoe)

obj = Employee()
obj.display()