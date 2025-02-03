mylist = ['Ram', 25, 10.0, True,  2+5j]

print(type(mylist))
print(len(mylist))
print(mylist[2])
print(mylist[-3])

print(mylist[::2])

mylist.append('Apple')

mylist.insert(1, 'Rahul')
print(mylist)

for i in mylist:
    print(i)

i = 0
while i < len(mylist):
    print(mylist[i])
    i += 1