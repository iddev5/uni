# tup = ('Ram', 20, -20.7, 2+5j, 75)

# print(type(tup), len(tup))

# print(tup[1:-1], tup[1:4])

# a = list(tup)
# a[2] = 'Rahul'
# tup = tuple(a)

# print(tup)

# append, insert, extend and remove 3rd using pop

tup = ('Ram', 20, -20.7, 2+5j, 75)

a = list(tup)

a.append('Hello')
a.insert(1, 999)
a.extend(['Another', 'list'])
elem = a.pop(2)

print(elem)

tup = tuple(a)

print(tup)

tup1 = (1, 2, 3)
tup3 = tup1 + tup
print(tup3)