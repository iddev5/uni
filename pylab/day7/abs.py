class CoffeeMachine:
    def __init__(self):
        self.__water_temp = 0
        self.__coffee_beans = 0

    def make_coffee(self):
        self.__heat_water()
        self.__grind_beans()
        print("Coffee is ready")

    def __heat_water(self):
        self.__water_temp = 200
        print("Water heated")

    def __grind_beans(self):
        self.__coffee_beans = 10
        print("Beans grinded")
        
# Object created
obj = CoffeeMachine()
obj.make_coffee()