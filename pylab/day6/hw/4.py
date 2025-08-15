class faculty:
    def about(self):
        self.id=int(input("enter the ID "))
        self.name=input("enter name ")
        self.salary=int(input("enter your salary "))
        self.feedback=int(input("enter feedback average "))
        self.age=int(input("enter your age "))
        self.yoe=int(input("Enter year of experience "))
    def display(self):
        print("your name is :",self.name)
        print("your ID is :",self.id)
        print("your salary is :",self.salary) 
        print("your feedback is :",self.feedback) 
        print("your age is :",self.age)
        print("Enter year of experience :",self.yoe)
obj=faculty()
obj.about()
obj.display()