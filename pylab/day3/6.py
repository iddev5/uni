password = input("Enter password to check: ")

valid = True
if len(password) < 8:
    print("Password must be 8 characters or more")
    valid = False

upper, lower = False, False
for c in password:
    if c.isupper():
        upper = True
    if c.islower():
        lower = True

if not upper:
    print("Password must have an uppercase character")

if not lower:
    print("Password must have a lowercase character")

if valid and upper and lower:
    print("Password is perfectly valid")
else:
    print("Password is invalid")