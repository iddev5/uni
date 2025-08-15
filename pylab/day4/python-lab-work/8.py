mylist = ["Hello", "Test", 15, "Python", 3.14, 10, True, 2+7j, ['T', 20]]
sep_list = []

for i in range(len(mylist)):
    prime = True
    for j in range(2, i // 2 + 1):
        if i % j == 0:
            prime = False
            break
    if prime:
        sep_list.append(mylist[i])

print(sep_list)