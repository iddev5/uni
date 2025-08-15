import math

a = int(input("Enter first number: "))
b = int(input("Enter second number: "))

gcd = math.gcd(a, b)
lcm = math.lcm(a, b)

print(f"GCD of two numbers is: {gcd}")
print(f"LCM of two numbers is: {lcm}")