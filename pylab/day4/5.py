set1 = {1, 2, 7, True, 0, 'Ram', False, 2, -7.0, 2+5j}
set2 = {70, 7, 2, True, 'hari', -20.0}

print(type(set1))

# True = 1, False = 0
print(len(set1), set1)

set3 = set1 | set2 # union
set4 = set1 & set2 # intersection
set5 = set1 - set2 # difference
set6 = set1 ^ set2 # symmetric_difference

print(set3)
print(set4)
print(set5)
print(set6)