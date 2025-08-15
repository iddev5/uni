mydict = {
    "Test": 20,
    "Abc": 30,
    "Python": 40,
    "Implement": 50,
    "Class": 60,
}

key = input("Enter key to check: ")

if key in mydict:
    print(key, "exists in dictionary")
else:
    print(key, "does not exists in dictionary")