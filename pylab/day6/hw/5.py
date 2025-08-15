class Circle:
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return 3.14 * self.radius * self.radius

    def perimeter(self):
        return 2 * 3.14 * self.radius

radius = int(input("Enter radius: "))
obj = Circle(radius)
print("Area is", obj.area())
print("Perimeter is", obj.perimeter())