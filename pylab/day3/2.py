# mylist = ['A', 1, 'B', 2, 'C', 3]
# elem = 'C'

# if elem in mylist:
#     print(elem, 'exists in list')
# else:
#     print(elem, 'does not exists')

mylist = [8, 23, 56, 9, 50, 21, 24]

i, largest, second = 0, 0, 0
while i < len(mylist):
    if mylist[i] > mylist[largest]:
        largest = i
    else:
        if mylist[i] > mylist[second]:
            second = i

    i += 1

print('Second largest element is:', mylist[second])