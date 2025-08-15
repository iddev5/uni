# mylist = ['A', 1, 'B', 2, 'C', 3]
# elem = 'C'

# if elem in mylist:
#     print(elem, 'exists in list')
# else:
#     print(elem, 'does not exists')

mylist = [8, 23, 56, 9, 51, 21, 24]

i, largest, second = 0, 0, 0
for i in range(len(mylist)):
    if mylist[i] > mylist[largest]:
        second = largest
        largest = i
    elif mylist[i] > mylist[second]:
        second = i

print('Second largest element is:', mylist[second])