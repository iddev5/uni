mylist = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

i = 0
while i < len(mylist) - 1:
    mylist[i], mylist[i+1] = mylist[i+1], mylist[i]
    i += 2

print(mylist)