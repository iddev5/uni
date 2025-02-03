string = input("Enter string to check: ")

rev = ""
for c in string:
    rev = c + rev

if rev == string:
    print(string, "is pallindrome")
else:
    print(string, "is not pallindrome")