import re

email = input("Enter an email to validate: ")

res = re.search('^[a-z]\w{7,}@[\w.]+$', email)

if res:
    print("Email is valid")
else:
    print("Email is invalid")