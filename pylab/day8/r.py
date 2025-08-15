import re

a = "Winter is coming."

b = re.search('^Winter.*.$', a)
if b:
    print("Matched")
else:
    print("Bye")

# b = re.findall('i', a)
# print(b)

# b = re.search('\s', a)
# print("Space at", b.start())

# b = re.split('\s', a)
# print(b)

b = re.sub('Winter', 'Dragon', a)
print(b)

