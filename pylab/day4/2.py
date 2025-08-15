mylist = ['Ram', 50, -20.7, 2+5j, 70]

print(mylist)

elem = mylist.pop()
print(elem, mylist)

elem = mylist.pop(1)
print(elem, mylist)

mylist.remove(-20.7)
print(mylist)

mylist.clear()
print(mylist)