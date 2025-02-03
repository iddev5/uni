dec = int(input("Enter a decimal number: "))
binary = ""

while dec > 0:
    binary = str(dec % 2) + binary
    dec //= 2

print("The binary representation is:", binary)