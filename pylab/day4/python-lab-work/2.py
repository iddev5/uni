groceries = {
    "apples": 2,
    "bananas": 4,
    "cashew": 3,
    "curd": 2,
    "peanut": 3,
    "grapes": 5,
    "oranges": 2,
}

new_groceries = {}

for item in groceries.items():
    if item[1] in new_groceries:
        temp = new_groceries[item[1]]
        if type(temp) is list:
            new_groceries[item[1]].append(item[0])
        else:
            new_groceries[item[1]] = [temp, item[0]]
    else:
        new_groceries[item[1]] = item[0]

print(new_groceries)