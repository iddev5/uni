# WAP to calculate compound interest

def compound_interest(p, r, n):
    return p * ((1.0 + (r / 100.0)) ** n)

p = int(input("Enter principle amount: "))
r = float(input("Enter rate of interest: "))
n = int(input("Enter time period in years: "))

print("Final amount is", compound_interest(p, r, n))