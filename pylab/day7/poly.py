class CSE: # First class
    def __init__(self, rank, perf):
        self.rank = rank
        self.perf = perf

    def power(self): # Same method
        print(f"The department performance is {self.perf} and rank is {self.rank}")

class IT: # Second class
    def __init__(self, rank, perf):
        self.rank = rank
        self.perf = perf

    def power(self): # Same method
        print(f"The department performance is {self.perf} and rank is {self.rank}")

class ETC: # Third class
    def __init__(self, rank, perf):
        self.rank = rank
        self.perf = perf

    def power(self):
        print(f"The department performance is {self.perf} and rank is {self.rank}")

class Architecture: # Fourth class
    def __init__(self, rank, perf):
        self.rank = rank
        self.perf = perf

    def power(self):
        print(f"The department performance is {self.perf} and rank is {self.rank}")

obj = CSE(1, '100%')
obj1 = IT(2, '90%')
obj2 = ETC(3, '85%')
obj3 = Architecture(4, '80%')

for i in [obj, obj1, obj2, obj3]:
    i.power()