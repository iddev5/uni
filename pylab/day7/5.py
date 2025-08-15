class System:
    pass

class Chips(System):
    def __init__(self):
        self.expensive = []
        self.perfect = []
        self.subpar = []

    def add_system(self):
        name = input("Enter system name: ")
        amount = int(input("Enter system amount: "))
        ptype = input("Enter processor type: ")

        system = {'name': name, 'amount': amount, 'ptype': ptype}

        if amount > 1000 and amount < 1500:
            self.expensive.append(system)
        elif amount > 500 and amount < 1000:
            self.perfect.append(system)
        else:
            self.subpar.append(system)

chips = Chips()
for i in range(3):
    chips.add_system()

print(f"Expensive systems: {chips.expensive}")
print(f"Perfect systems: {chips.perfect}")
print(f"Subpar systems: {chips.subpar}")