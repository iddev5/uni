class student:
    def about(self):
        self.id=int(input("enter the ID"))
        self.name=input("enter name")
        self.roll=int(input("enter roll number"))
        self.branch=input("enter branch name")
        self.cgpa=int(input("enter your cgpa"))
    def display(self):
        print("your name is",self.name)
        print("your ID is",self.id)
        print("your ROLL number is",self.roll) 
        print("your branch is",self.branch) 
        print("your CGPA is",self.cgpa)
obj=student()
obj.about()
obj.display()