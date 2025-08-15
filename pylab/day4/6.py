abc = {
    'branch': 'cse',
    'name': 'Ayush',
    'roll_no': 137,
    'name': 'Ram'
}

print(type(abc))

print(len(abc))

print(abc)

a = abc.keys()
print(a)

b = abc.values()
print(b)

print(abc["branch"])

print(abc.get('branch'))

c = abc.items()
print(c)

abc['marks'] = 85
abc['cgpa'] = 9.38

print(abc)