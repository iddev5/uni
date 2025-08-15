MIN_FUEL_CAP = 50
MAX_FUEL_CAP = 1000
MAX_SPEED = 150
MAX_ENGINE_CAP = 5000

class Vehicle:
    def __init__(self, speed):
        speed_dif = speed / (MAX_SPEED)
        self.speed = speed
        self.engine_cap = speed_dif * MAX_ENGINE_CAP
        self.fuel_cap = max((1.0 - speed_dif) * MAX_FUEL_CAP, MIN_FUEL_CAP)

    def print_stats(self):
        print(f"Speed is {self.speed}")
        print(f"Engine cap is {self.engine_cap} GHz")
        print(f"Fuel cap is {self.fuel_cap} L")

class Sports(Vehicle):
    def __init__(self, speed):
        super().__init__(speed)

    def print_stats(self):
        print("Category: Sports car")
        super().print_stats()

class Heavy(Vehicle):
    def __init__(self, speed):
        super().__init__(speed)

    def print_stats(self):
        print("Category: Heavy vehicle")
        super().print_stats()

class Luxorious(Vehicle):
    def __init__(self, speed):
        super().__init__(speed)

    def print_stats(self):
        print("Category: Luxorious car")
        super().print_stats()

veh = None
speed = int(input("Enter speed of vehicle: "))

if speed > 120:
    veh = Sports(speed)
elif speed > 90:
    veh = Luxorious(speed)
elif speed >= 50:
    veh = Heavy(speed)
else:
    print("Speed cannot be less than 50")
    exit(1)

veh.print_stats()