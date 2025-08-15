mylist = [1, 2, 3, 2, 5, "Hello", "hi", True, "test", 2+5j, 2, "hi"]
myset = set()

for item in mylist:
    myset.add(item)

print("List as set: ", myset)