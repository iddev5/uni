# Program 1
D = {
    'T1': ['E', 'K', 'M', 'N', 'O', 'Y'],
    'T2': ['D', 'E', 'K', 'N', 'O', 'Y'],
    'T3': ['A', 'E', 'K', 'M'],
    'T4': ['C', 'K', 'M', 'U', 'Y'],
    'T5': ['C', 'E', 'I', 'K', 'O', 'O'],
}

support_values = {}

for values in D.values():
    for val in values:
        if val not in support_values:
            support_values[val] = 1
        else:
            support_values[val] += 1

print(support_values)

# Program 2

D1_list = list(support_values.items())

for i in range(len(D1_list)):
    for j in range(len(D1_list) - i - 1):
        if D1_list[j][1] < D1_list[j+1][1]:
            D1_list[j], D1_list[j+1] = D1_list[j+1], D1_list[j]

D1_sorted = {}

for it in D1_list:
    D1_sorted[it[0]] = it[1]

print(D1_sorted)

# Program 3

D1 = support_values.copy()

to_remove = []
for it in D1.items():
    if it[1] < 3:
        to_remove.append(it[0])

for it in to_remove:
    D1.pop(it)

print(D1)

# Program 4

new_D = D.copy()

for item in new_D.items():
    to_remove = []

    for value in item[1]:
        keys = list(D1.keys())
        if keys.count(value) == 0:
            to_remove.append(value)

    for rem in to_remove:
        new_D[item[0]].remove(rem)

print(new_D)